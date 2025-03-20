import {
  WebGLRenderer,
  Clock,
} from "https://cdnjs.cloudflare.com/ajax/libs/three.js/0.172.0/three.module.min.js";

export default class Graphic extends WebGLRenderer {
  scene = null;
  clock = new Clock();
  camera = null;
  cbUpdate = null;
  cbLoop = null;
  isRunning = true;

  constructor(scene, camera) {
    const canvas = document.getElementById("PongGame");
    super({
      canvas: canvas,
      antialias: true,
    });
    this.scene = scene;
    this.camera = camera;
    this.cbLoop = this.loop.bind(this);
    this.shadowMap.enabled = true;
    this.loop();
  }

  loop() {
    if (!this.isRunning) return;

    const dt = this.clock.getDelta();
    if (this.cbUpdate) this.cbUpdate(dt);
    this.render(this.scene, this.camera);
    requestAnimationFrame(this.cbLoop);
  }

  dispose() {
    this.isRunning = false;
    this.scene.traverse((object) => {
      if (object.geometry) {
        object.geometry.dispose();
      }
      if (object.material) {
        if (Array.isArray(object.material)) {
          object.material.forEach((material) => material.dispose());
        } else {
          object.material.dispose();
        }
      }
    });

    this.dispose();

    this.scene = null;
    this.camera = null;
    this.cbUpdate = null;
    this.cbLoop = null;
  }

  onUpdate(callback) {
    this.cbUpdate = callback;
  }

  getDomElement() {
    return this.domElement;
  }
}
