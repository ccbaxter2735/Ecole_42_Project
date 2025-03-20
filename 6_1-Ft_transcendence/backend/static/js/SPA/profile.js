import { getFetchConfigWithCSRF } from "./router.js";
import { showNotification, isAlphanumeric } from "./login.js";

async function editProfile() {
  const changeUsernameBtn = document.getElementById("changeUsername");
  const usernameInput = document.getElementById("username");
  const changePasswordBtn = document.getElementById("changeProfile");
  const passwordInput = document.getElementById("name");
  const profilePicInput = document.getElementById("profilePic");
  const fetchProfile = await fetch("/api/game/profile/");
  const dataProfile = await fetchProfile.json();

  if (dataProfile.is_42) {
    changeUsernameBtn.disabled = true;
    changePasswordBtn.disabled = true;
    profilePicInput.disabled = true;
    usernameInput.disabled = true;
    passwordInput.disabled = true;

    showNotification("forty_two_user_edit", "warning");

    return;
  }

  async function editUsername() {
    changeUsernameBtn.addEventListener("click", async () => {
      const newUsername = usernameInput.value.trim();
      if (!newUsername) return;

      if (!isAlphanumeric(newUsername)) {
        showNotification("username_alphanumeric_only", "danger");
        return;
      }

      if (newUsername.length > 20) {
        showNotification("username_length_error", "danger");
        return;
      }

      if (newUsername.length < 3) {
        showNotification("username_length_min_error", "danger");
        return;
      }

      try {
        const fetchConfigWithCSRF = await getFetchConfigWithCSRF();
        const response = await fetch("/api/game/modifuser/", {
          method: "POST",
          ...fetchConfigWithCSRF,
          body: JSON.stringify({
            newName: newUsername,
          }),
        });
        if (response.ok) {
          showNotification("profile_update_success", "success");
          document.getElementById("profile-username").textContent = newUsername;
        } else {
          showNotification("profile_update_error", "danger");
        }
      } catch (error) {
        showNotification("username_update_error", "danger");
      }
    });
  }

  async function editPassword() {
    changePasswordBtn.addEventListener("click", async () => {
      const newPassword = passwordInput.value.trim();

      if (!newPassword) return;

      if (newPassword.length > 20) {
        showNotification("password_length_error", "danger");
        return;
      }

      if (newPassword.length < 3) {
        showNotification("password_length_min_error", "danger");
        return;
      }

      try {
        const fetchConfigWithCSRF = await getFetchConfigWithCSRF();
        const response = await fetch("/api/game/modifpass/", {
          method: "POST",
          ...fetchConfigWithCSRF,
          body: JSON.stringify({
            new_password: newPassword,
          }),
        });

        if (response.ok) {
          showNotification("profile_update_success", "success");
        } else {
          showNotification("profile_update_error", "danger");
        }
      } catch (error) {
        showNotification("password_update_error", "danger");
      }
    });
  }

  async function editAvatar() {
    profilePicInput.addEventListener("change", async (event) => {
      const file = event.target.files[0];
      if (!file) return;

      const formData = new FormData();
      formData.append("avatar", file);

      try {
        const fetchConfigWithCSRF = await getFetchConfigWithCSRF();
        const response = await fetch("/api/game/modifavatar/", {
          method: "POST",
          ...fetchConfigWithCSRF,
          body: formData,
        });

        if (response.ok) {
          const imageUrl = URL.createObjectURL(file);
          document.getElementById("profile-image").src = imageUrl;
          setTimeout(() => URL.revokeObjectURL(imageUrl), 1000);
          showNotification("profile_update_success", "success");
        } else {
          showNotification("profile_update_error", "danger");
        }
      } catch (error) {
        showNotification("avatar_update_error", "danger");
      }
    });
  }

  editUsername();
  editPassword();
  editAvatar();
}

async function printStatProfile() {
  try {
    const response = await fetch("/api/game/profile/");
    const data = await response.json();

    const imageUrl = data.profile_image.startsWith("http")
      ? data.profile_image
      : `/media/images/${data.profile_image.split("/").pop()}`;

    document.getElementById("profile-username").textContent = data.username;
    document.getElementById("profile-image").src = imageUrl;
    document.getElementById("win_profile_id").textContent = data.match_win;
    document.getElementById("losses_profile_id").textContent = data.match_lost;
    document.getElementById("total_profile_id").textContent =
      data.match_win + data.match_lost;

    const circle = document.querySelector(".circle-progress");
    const radius = circle.r.baseVal.value;
    const circumference = 2 * Math.PI * radius;
    circle.style.strokeDasharray = circumference;

    const total = data.match_win + data.match_lost;
    const winPercentage = total === 0 ? 0 : (data.match_win / total) * 100;

    const offset = circumference - (winPercentage / 100) * circumference;
    circle.style.strokeDashoffset = offset;

    document.getElementById("win-percentage").textContent =
      `${Math.round(winPercentage)}%`;
  } catch (error) {
    console.error("Error Profile");
  }
}

async function printHistoryProfile() {
  try {
    const response = await fetch("/api/game/history/");
    const data = await response.json();
    const historyContainer = document.getElementById("history");

    const table = document.createElement("table");
    table.className = "table table-striped";
    const tbody = document.createElement("tbody");

    data.forEach((match) => {
      const row = document.createElement("tr");
      const date = new Date(match.created_at).toLocaleString("fr-FR", {
        year: "numeric",
        month: "numeric",
        day: "numeric",
        hour: "2-digit",
        minute: "2-digit",
      });

      row.innerHTML = `
        <td>${date}</td>
        <td>${match.username}</td>
        <td>${match.user_score}</td>
        <td>${match.enemy_name}</td>
        <td>${match.enemy_score}</td>
      `;

      if (match.user_score > match.enemy_score) {
        row.classList.add("table-success");
      } else if (match.user_score < match.enemy_score) {
        row.classList.add("table-danger");
      }

      tbody.appendChild(row);
    });

    table.appendChild(tbody);
    historyContainer.innerHTML = "";
    historyContainer.appendChild(table);
  } catch (error) {
    console.error("Error history");
  }
}

async function printFriendList() {
  try {
    const response = await fetch("/api/game/listfriend/");
    const data = await response.json();
    const friendContainer = document.getElementById("friend");

    const table = document.createElement("table");
    table.className = "table table-striped";
    const tbody = document.createElement("tbody");

    data.forEach((friend) => {
      const row = document.createElement("tr");
      row.innerHTML = `
        <td>${friend.username}</td>
        <td>
          <span class="badge ${friend.is_online ? "bg-success" : "bg-danger"}">
            ${friend.is_online ? "" : ""}
          </span>
        </td>
      `;
      tbody.appendChild(row);
    });

    table.appendChild(tbody);
    friendContainer.innerHTML = "";
    friendContainer.appendChild(table);
  } catch (error) {
    console.error("Error friendlist");
  }
}

export async function setupProfilePageEvents() {
  if (document.readyState === "loading") {
    document.addEventListener("DOMContentLoaded", async () => {
      await initializeProfile();
    });
  } else {
    await initializeProfile();
  }
}

async function initializeProfile() {
  editProfile();

  await Promise.all([
    printStatProfile(),
    printHistoryProfile(),
    printFriendList(),
  ]);
}
