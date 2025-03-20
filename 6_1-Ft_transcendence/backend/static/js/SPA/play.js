import { initTournament, pong } from "../game/index.js";
import { handleLocation } from "./router.js";
import { showNotification, isAlphanumeric } from "./login.js";

function cleanupModal(modalId) {
  var modalElement = document.getElementById(modalId);
  var modalInstance = bootstrap.Modal.getInstance(modalElement);
  if (modalInstance) {
    modalInstance.hide();
  }
  var backdrop = document.querySelector(".modal-backdrop");
  if (backdrop) {
    backdrop.remove();
  }
  document.body.classList.remove("modal-open");
}

async function navigateToGame() {
  window.history.pushState({}, "", "/game");
  await handleLocation();
}

function validatePlayerName(playerName) {
  if (!isAlphanumeric(playerName)) {
    showNotification("player_name_alphanumeric_only", "danger");
    return false;
  }

  if (playerName.length > 10) {
    showNotification("player_name_too_long", "danger");
    return false;
  }
  if (playerName.length < 3) {
    showNotification("player_name_too_short", "danger");
    return false;
  }
  return true;
}

async function handleVersusSubmit(event, username) {
  event.preventDefault();
  var playerNameElement = document.getElementById("versusPlayerName");
  var playerName = playerNameElement ? playerNameElement.value.trim() : "";

  if (!playerName) {
    showNotification("player_name_required", "danger");
    return;
  }

  const usedNames = document.querySelectorAll(".player-name");
  const usedNamesArray = Array.from(usedNames).map((el) =>
    el.textContent.trim().toLowerCase(),
  );

  if (
    usedNamesArray.includes(playerName.toLowerCase()) ||
    playerName.toLowerCase() === username.toLowerCase()
  ) {
    showNotification("player_name_already_used", "danger");
    return;
  }

  if (!validatePlayerName(playerName)) {
    return;
  }

  cleanupModal("versusModal");
  await navigateToGame();
  pong(username, playerName, false);
}

function handleTournamentSubmit(event) {
  event.preventDefault();
  var players = [];
  var playerNames = new Set();

  for (var i = 1; i <= 4; i++) {
    var playerInput = document.getElementById("player" + i + "Name");
    if (playerInput) {
      var playerName = playerInput.value.trim();

      if (!playerName) {
        showNotification("all_player_names_required", "danger");
        return;
      }

      if (!validatePlayerName(playerName)) {
        return;
      }

      if (playerNames.has(playerName.toLowerCase())) {
        showNotification("player_names_must_be_unique", "danger");
        return;
      }

      playerNames.add(playerName.toLowerCase());
      players.push(playerName);
    }
  }

  if (players.length === 4) {
    cleanupModal("tournamentModal");
    initTournament(players);
  }
}

async function handleAIClick(username) {
  await navigateToGame();
  pong(username, "IA", false);
}

function setupGameModes(username) {
  var versusForm = document.getElementById("versusForm");
  if (versusForm) {
    versusForm.addEventListener("submit", function (event) {
      handleVersusSubmit(event, username);
    });
  }

  var tournamentForm = document.getElementById("tournamentForm");
  if (tournamentForm) {
    tournamentForm.addEventListener("submit", handleTournamentSubmit);
  }

  var aiBtn = document.getElementById("aiBtn");
  if (aiBtn) {
    aiBtn.addEventListener("click", function () {
      handleAIClick(username);
    });
  }
}

export async function setupPlayPageEvents() {
  var response = await fetch("/api/game/profile");
  var data = await response.json();
  var username = data.username;
  setupGameModes(username);
}
