import { GUI } from "https://unpkg.com/dat.gui@0.7.9/build/dat.gui.module.js";

export default class Custom extends GUI {
  constructor(p1, p2, wTop, wBot, ball, physic, p1Name, p2Name) {
    super({ autoPlace: false });
    this.p1 = p1;
    this.p2 = p2;
    this.p1Name = p1Name;
    this.p2Name = p2Name;
    this.wTop = wTop;
    this.wBot = wBot;
    this.ball = ball;
    this.physic = physic;

    this.colorFolder = this.addFolder("Color");
    this.physicFolder = this.addFolder("Physic");

    if (p2Name === "IA") {
      this.iaFolder = this.addFolder("IA Settings");
      this.iaFolderUpdate();
    }

    this.Style();
    this.colorFolderUpdate();
    this.physicFolderUpdate();
  }

  hide() {
    this.domElement.style.display = "none";
  }

  show() {
    this.domElement.style.display = "block";
  }

  Style() {
    const container = document.getElementById("game-container");
    container.appendChild(this.domElement);

    this.domElement.style.position = "absolute";
    this.domElement.style.bottom = "350px";
    this.domElement.style.left = "15px";
    this.domElement.style.z_index = "10";
    this.domElement.style.display = "block";
  }

  colorFolderUpdate() {
    const guiParams = {
      p1Color: this.p1.material.color.getHex(),
      p2Color: this.p2.material.color.getHex(),
      wTopColor: this.wTop.material.color.getHex(),
      wBotColor: this.wBot.material.color.getHex(),
      ballColor: this.ball.material.color.getHex(),
    };

    this.colorFolder
      .addColor(guiParams, "p1Color")
      .name(this.p1Name)
      .onChange((value) => {
        this.p1.material.color.set(value);
      });

    this.colorFolder
      .addColor(guiParams, "p2Color")
      .name(this.p2Name)
      .onChange((value) => {
        this.p2.material.color.set(value);
      });

    this.colorFolder
      .addColor(guiParams, "wTopColor")
      .name("Wall Top")
      .onChange((value) => {
        this.wTop.material.color.set(value);
      });

    this.colorFolder
      .addColor(guiParams, "wBotColor")
      .name("Wall Bot")
      .onChange((value) => {
        this.wBot.material.color.set(value);
      });

    this.colorFolder
      .addColor(guiParams, "ballColor")
      .name("Ball")
      .onChange((value) => {
        this.ball.material.color.set(value);
      });
  }

  iaFolderUpdate() {
    const guiParams = {
      reactionDelay: this.ball.controls.reactionDelay,
      errorRate: this.ball.controls.errorRate,
    };

    this.iaFolder
      .add(guiParams, "reactionDelay", 0, 600, 10)
      .name("Reaction Delay (ms)")
      .onChange((value) => {
        this.ball.controls.reactionDelay = value;
      });

    this.iaFolder
      .add(guiParams, "errorRate", 0, 0.9, 0.05)
      .name("Error Rate")
      .onChange((value) => {
        this.ball.controls.errorRate = value;
      });
  }
  physicFolderUpdate() {
    const guiParams = {
      initialSpeed: this.physic.initialSpeed,
      maxSpeed: this.physic.maxSpeed,
      boost: this.physic.boost,
      goal: this.physic.goal,
      score: this.physic.scoreMax,
    };

    this.physicFolder
      .add(guiParams, "initialSpeed", 1, 50, 1)
      .name("Initial Speed")
      .onChange((value) => {
        this.physic.initialSpeed = value;
        this.physic.resetBall();
      });

    this.physicFolder
      .add(guiParams, "maxSpeed", 1, 120, 1)
      .name("Max Speed")
      .onChange((value) => {
        this.physic.maxSpeed = value;
      });

    this.physicFolder
      .add(guiParams, "boost", 0.1, 3, 0.1)
      .name("Boost")
      .onChange((value) => {
        this.physic.boost = value;
      });

    this.physicFolder
      .add(guiParams, "score", 1, 10, 1)
      .name("Winning Score")
      .onChange((value) => {
        this.physic.scoreMax = value;
      });
  }
}
