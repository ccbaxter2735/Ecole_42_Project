import { getFetchConfigWithCSRF } from "./router.js";

async function manageFriend(username, isAdding) {
  const action = isAdding ? "add" : "remove";

  try {
    const fetchConfigWithCSRF = await getFetchConfigWithCSRF();

    const response = await fetch(`/api/game/friends/${action}/`, {
      method: "POST",
      ...fetchConfigWithCSRF,
      body: JSON.stringify({ username }),
    });

    if (!response.ok) {
      throw new Error(`HTTP Error: ${response.status}`);
    }
    return await response.json();
  } catch (error) {
    console.error(`Erreur lors de la gestion d'ami:`, error);
    throw error;
  }
}

async function createLeaderboardRow(player, index, activeUser, friendList) {
  const row = document.createElement("tr");

  row.innerHTML = `
    <th scope="row">${index + 1}</th>
    <td>${player.username}</td>
    <td>${player.match_win}</td>
    <td>${player.match_lost}</td>
  `;

  if (player.username !== activeUser) {
    const isFriend =
      friendList.find((friend) => friend.username === player.username)
        ?.is_friend || false;

    const switchCell = document.createElement("td");
    switchCell.innerHTML = `
      <div class="form-check form-switch">
        <input class="form-check-input" 
               type="checkbox" 
               id="friend-switch-${player.username}"
               ${isFriend ? "checked" : ""}>
      </div>
    `;

    switchCell.querySelector("input").addEventListener("change", async (e) => {
      const originalState = e.target.checked;
      try {
        await manageFriend(player.username, originalState);
      } catch (error) {
        console.error("Erreur lors de la gestion d'ami:", error);
        e.target.checked = !originalState;
      }
    });

    row.appendChild(switchCell);
  } else {
    row.appendChild(document.createElement("td"));
  }

  return row;
}

export async function setupLeaderboardPageEvents() {
  const fetchConfigWithCSRF = await getFetchConfigWithCSRF();

  const profileResponse = await fetch("/api/game/profile", {
    ...fetchConfigWithCSRF,
  });
  const profileData = await profileResponse.json();
  const activeUser = profileData?.username;

  const friendListResponse = await fetch("/api/game/listuser/", {
    ...fetchConfigWithCSRF,
  });
  const friendList = await friendListResponse.json();

  const leaderboardResponse = await fetch("/api/game/leaderboard", {
    ...fetchConfigWithCSRF,
  });
  const leaderboardData = await leaderboardResponse.json();

  if (!activeUser || !friendList || !leaderboardData) return;

  const sortedLeaderboard = leaderboardData.sort(
    (a, b) => b.match_win - a.match_win,
  );

  const leadBody = document.getElementById("lead-body");
  leadBody.innerHTML = "";

  const rowPromises = sortedLeaderboard.map((player, index) =>
    createLeaderboardRow(player, index, activeUser, friendList),
  );

  const rows = await Promise.all(rowPromises);

  leadBody.append(...rows);
}
