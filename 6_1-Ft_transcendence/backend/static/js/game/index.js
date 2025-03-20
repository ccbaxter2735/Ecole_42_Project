import * as THREE from "https://cdnjs.cloudflare.com/ajax/libs/three.js/0.172.0/three.module.min.js";
import Camera from "./camera.js";
import Light from "./light.js";
import Graphic from "./graphic.js";
import Player from "./player.js";
import Ball from "./ball.js";
import MiddleBar from "./middlebar.js";
import Wall from "./wall.js";
import Controls from "./controls.js";
import Physic from "./physic.js";
import Custom from "./custom.js";
import { handleLocation } from "../SPA/router.js";

export const tournamentState = {
  players: [],
  winners: [],
  currentRound: 0,
  isActive: false,
};

function showWinnerModal(winnerName) {
  const modalHTML = `
    <div class="modal fade" id="winnerModal" tabindex="-1" aria-hidden="true">
      <div class="modal-dialog modal-dialog-centered">
        <div class="modal-content">
          <div class="modal-header">
            <h5 class="modal-title" data-i18n="tournament_winner">CHAMPIOOOON</h5>
            <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
          </div>
          <div class="modal-body text-center">
            <h2 class="mb-4">🏆🏆${winnerName}🏆🏆</h2>
          </div>
          <div class="modal-footer">
            <button type="button" class="btn btn-primary" data-bs-dismiss="modal">🏠</button>
          </div>
        </div>
      </div>
    </div>
  `;

  document.body.insertAdjacentHTML("beforeend", modalHTML);
  const winnerModal = new bootstrap.Modal(
    document.getElementById("winnerModal"),
  );
  winnerModal.show();

  document
    .getElementById("winnerModal")
    .addEventListener("hidden.bs.modal", function () {
      this.remove();
      window.history.pushState({}, "", "/");
      handleLocation();
    });
}

export function initTournament(players) {
  tournamentState.players = [...players];
  tournamentState.winners = [];
  tournamentState.currentRound = 0;
  tournamentState.isActive = true;

  window.history.pushState({}, "", "/game");
  handleLocation().then(() => {
    pong(players[0], players[1], true);
  });
}

export function pong(p1Name, p2Name, isTournament = false) {
  const startButton = document.getElementById("start");
  const exitButton = document.getElementById("exit");
  const nextButton = document.getElementById("next");
  const nameP1Element = document.getElementById("name-p1");
  const nameP2Element = document.getElementById("name-p2");

  exitButton.style.display = "none";
  nextButton.style.display = "none";

  const SIZE_X = 40;
  const SIZE_Z = 30;

  const scene = new THREE.Scene();
  const camera = new Camera();
  const light = new Light();
  const graphic = new Graphic(scene, camera);

  const p1 = new Player(SIZE_X / 2 - SIZE_X, 0, 0, p1Name, "name-p1");
  const p2 = new Player(SIZE_X / 2, 0, 0, p2Name, "name-p2");

  const ball = new Ball(0, 0, 0);
  const middleBar = new MiddleBar();

  const wTop = new Wall(0, 0, SIZE_Z / 2 - SIZE_Z);
  const wBot = new Wall(0, 0, SIZE_Z / 2);

  const controls = new Controls(p1, p2, wTop, wBot, ball);

  const physic = new Physic(
    p1,
    p2,
    wTop,
    wBot,
    ball,
    resetGameStartVersus,
    resetGameStartTournament,
    isTournament,
    {
      initialSpeed: 15,
      maxSpeed: 60,
      boost: 1.2,
      goal: 23,
      score: 2,
    },
  );

  const custom = new Custom(p1, p2, wTop, wBot, ball, physic, p1Name, p2Name);

  [wTop, wBot, ball, middleBar, light, p1, p2].forEach((obj) => scene.add(obj));

  let start = false;

  function resetGameStartTournament() {
    start = false;
    startButton.style.display = "none";
    nextButton.style.display = "block";
    exitButton.style.display = "block";

    nextButton.replaceWith(nextButton.cloneNode(true));
    const newNextButton = document.getElementById("next");

    newNextButton.addEventListener("click", () => {
      if (tournamentState.isActive) {
        const winner =
          physic.getScoreP1() > physic.getScoreP2() ? p1Name : p2Name;
        tournamentState.winners.push(winner);

        if (tournamentState.currentRound === 0) {
          tournamentState.currentRound++;
          window.history.pushState({}, "", "/game");
          handleLocation().then(() => {
            pong(tournamentState.players[2], tournamentState.players[3], true);
          });
        } else if (tournamentState.currentRound === 1) {
          tournamentState.currentRound++;
          window.history.pushState({}, "", "/game");
          handleLocation().then(() => {
            pong(tournamentState.winners[0], tournamentState.winners[1], true);
          });
        } else {
          const finalWinner =
            physic.getScoreP1() > physic.getScoreP2() ? p1Name : p2Name;
          showWinnerModal(finalWinner);
          tournamentState.isActive = false;
        }
      }
    });
  }

  function resetGameStartVersus() {
    start = false;
    startButton.style.display = "block";
    exitButton.style.display = "block";

    exitButton.addEventListener("click", () => {
      window.history.pushState({}, "", "/");
      handleLocation();
    });
  }
  function startGameHandler() {
    if (!start) {
      start = true;
      startButton.style.display = "none";
      exitButton.style.display = "none";
    }
  }

  graphic.onUpdate((dt) => {
    if (start) {
      if (p2.name === "IA") controls.launchIA(dt);
      else controls.launch(dt);
      physic.launch(dt);
      custom.hide();
    }

    graphic.setSize(window.innerWidth, window.innerHeight);
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
  });
  startButton.addEventListener("click", startGameHandler);
}
