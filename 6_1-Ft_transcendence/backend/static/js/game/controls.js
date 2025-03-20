const PLAYER_SPEED = 35;

export default class Controls {
  constructor(p1, p2, wTop, wBot, ball) {
    this.keysPressed = {};
    this.p1 = p1;
    this.p2 = p2;
    this.wTop = wTop;
    this.wBot = wBot;
    this.ball = ball;
    this.ball.controls = this;
    this.reactionDelay = 200;
    this.errorRate = 0.2;
    this.lastIAUpdate = 0;

    document.addEventListener("keydown", (event) => {
      this.keysPressed[event.key] = true;
    });

    document.addEventListener("keyup", (event) => {
      this.keysPressed[event.key] = false;
    });
  }

  launch(dt) {
    if (this.keysPressed["w"] || this.keysPressed["W"]) {
      if (!this.p1.getBox().intersectsBox(this.wTop.getBox())) {
        this.p1.position.z -= PLAYER_SPEED * dt;
      }
    }

    if (this.keysPressed["s"] || this.keysPressed["S"]) {
      if (!this.p1.getBox().intersectsBox(this.wBot.getBox())) {
        this.p1.position.z += PLAYER_SPEED * dt;
      }
    }
    if (this.keysPressed["ArrowUp"]) {
      if (!this.p2.getBox().intersectsBox(this.wTop.getBox())) {
        this.p2.position.z -= PLAYER_SPEED * dt;
      }
    }

    if (this.keysPressed["ArrowDown"]) {
      if (!this.p2.getBox().intersectsBox(this.wBot.getBox())) {
        this.p2.position.z += PLAYER_SPEED * dt;
      }
    }
    this.p1.updateBox();
    this.p2.updateBox();
  }
  shouldMakeError() {
    return Math.random() < this.errorRate;
  }

  launchIA(dt) {
    if (this.keysPressed["w"] || this.keysPressed["W"]) {
      if (!this.p1.getBox().intersectsBox(this.wTop.getBox())) {
        this.p1.position.z -= PLAYER_SPEED * dt;
      }
    }

    if (this.keysPressed["s"] || this.keysPressed["S"]) {
      if (!this.p1.getBox().intersectsBox(this.wBot.getBox())) {
        this.p1.position.z += PLAYER_SPEED * dt;
      }
    }

    const currentTime = Date.now();
    if (currentTime - this.lastIAUpdate >= this.reactionDelay) {
      this.lastIAUpdate = currentTime;

      if (this.shouldMakeError()) {
        // Mouvement aléatoire en cas d'erreur
        if (Math.random() < 0.5) {
          if (!this.p2.getBox().intersectsBox(this.wTop.getBox())) {
            this.p2.position.z -= PLAYER_SPEED * dt;
          }
        } else {
          if (!this.p2.getBox().intersectsBox(this.wBot.getBox())) {
            this.p2.position.z += PLAYER_SPEED * dt;
          }
        }
      } else {
        // Suivi de la balle
        if (this.p2.position.z > this.ball.position.z + this.p2.height / 4) {
          if (!this.p2.getBox().intersectsBox(this.wTop.getBox())) {
            this.p2.position.z -= PLAYER_SPEED * dt;
          }
        } else if (
          this.p2.position.z <
          this.ball.position.z - this.p2.height / 4
        ) {
          if (!this.p2.getBox().intersectsBox(this.wBot.getBox())) {
            this.p2.position.z += PLAYER_SPEED * dt;
          }
        }
      }
    }

    this.p1.updateBox();
    this.p2.updateBox();
  }
}
