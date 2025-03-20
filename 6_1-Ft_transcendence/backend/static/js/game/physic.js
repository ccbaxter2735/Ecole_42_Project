import { getFetchConfigWithCSRF } from "../SPA/router.js";

export default class Physic {
  constructor(
    p1,
    p2,
    wTop,
    wBot,
    ball,
    resetGameStartVersus,
    resetGameStartTournament,
    isTournament = false,
    {
      initialSpeed = 15,
      maxSpeed = 60,
      boost = 1.2,
      goal = 23,
      score = 2,
    } = {},
  ) {
    this.p1 = p1;
    this.p2 = p2;
    this.wTop = wTop;
    this.wBot = wBot;
    this.ball = ball;
    this.resetGameStartVersus = resetGameStartVersus;
    this.resetGameStartTournament = resetGameStartTournament;
    this.isTournament = isTournament;

    this.initialSpeed = initialSpeed;
    this.maxSpeed = maxSpeed;
    this.boost = boost;
    this.goal = goal;
    this.scoreMax = score;

    this.vx = 0;
    this.vz = 0;
    this.isProcessingScore = false;
    this.pLock = false;
    this.wLock = false;
    this.resetBall();
  }
  wHit() {
    if (
      this.ball.touchBox(this.wTop.getBox()) ||
      (this.ball.touchBox(this.wBot.getBox()) && !this.wLock)
    ) {
      this.wLock = true;
      this.vz *= -1;
    }
    if (
      !this.ball.touchBox(this.p1.getBox()) &&
      !this.ball.touchBox(this.p2.getBox()) &&
      this.wLock
    ) {
      this.wLock = false;
    }
  }

  pHit() {
    if (
      (this.ball.touchBox(this.p1.getBox()) ||
        this.ball.touchBox(this.p2.getBox())) &&
      !this.pLock
    ) {
      this.pLock = true;
      const angle = (Math.random() * Math.PI) / 4 - Math.PI / 8;
      const sign = this.ball.position.z > this.p1.position.z ? -1 : +1;
      const currentSpeed = Math.sqrt(this.vx * this.vx + this.vz * this.vz);

      this.vz = sign * Math.sin(angle) * currentSpeed;
      this.vx *= -1;

      if (Math.abs(this.vx) < this.maxSpeed) {
        this.vx *= this.boost;
      }
    }

    if (
      !this.ball.touchBox(this.p1.getBox()) &&
      !this.ball.touchBox(this.p2.getBox())
    ) {
      this.pLock = false;
    }
  }

  resetBall() {
    this.ball.position.set(0, 0, 0);

    const angle = (Math.random() * Math.PI) / 4 - Math.PI / 8;
    const direction = Math.random() < 0.5 ? -1 : 1;

    this.vx = direction * this.initialSpeed;
    this.vz = Math.sin(angle) * this.initialSpeed;
  }

  getScoreP1() {
    return this.p1.score;
  }

  getScoreP2() {
    return this.p2.score;
  }

  async pScore() {
    if (this.isProcessingScore) return;
    if (this.ball.position.x <= -this.goal) {
      this.resetBall();
      this.p2.score++;
      this.p2.printScore("score-p2");
    }
    if (this.ball.position.x >= this.goal) {
      this.resetBall();
      this.p1.score++;
      this.p1.printScore("score-p1");
    }

    if (this.p1.score === this.scoreMax || this.p2.score === this.scoreMax) {
      if (!this.isTournament) {
        this.isProcessingScore = true;
        const formData = {
          username: this.p1.name,
          enemy_name: this.p2.name,
          user_score: this.p1.score,
          enemy_score: this.p2.score,
        };

        const config = await getFetchConfigWithCSRF();

        await fetch("/api/game/createHistoryEntry/", {
          ...config,
          method: "POST",
          headers: {
            ...config.headers,
            "Content-Type": "application/json",
          },
          body: JSON.stringify(formData),
        });

        if (this.p1.score > this.p2.score) {
          await fetch("/api/game/addwin/", {
            ...config,
            method: "POST",
            headers: {
              ...config.headers,
              "Content-Type": "application/json",
            },
          });
        } else {
          await fetch("/api/game/addlose/", {
            ...config,
            method: "POST",
            headers: {
              ...config.headers,
              "Content-Type": "application/json",
            },
          });
        }
      }

      this.resetBall();
      this.p1.score = 0;
      this.p2.score = 0;
      this.p1.printScore("score-p1");
      this.p2.printScore("score-p2");

      if (this.isTournament) {
        this.resetGameStartTournament();
      } else {
        this.resetGameStartVersus();
      }
    }
    this.isProcessingScore = false;
  }

  launch(dt) {
    this.wHit();
    this.pHit();
    this.pScore();
    this.ball.position.x += this.vx * dt;
    this.ball.position.z += this.vz * dt;
    this.ball.updateBox();
  }
}
