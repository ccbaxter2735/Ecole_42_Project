import { PerspectiveCamera } from "https://cdnjs.cloudflare.com/ajax/libs/three.js/0.172.0/three.module.min.js";

export default class Camera extends PerspectiveCamera {
  constructor() {
    super(70, innerWidth / innerHeight);
    this.position.set(0, 25, 20);
    this.lookAt(0, 0, 0);
  }
  getCamera() {
    return this;
  }
}
