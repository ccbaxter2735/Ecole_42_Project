import {
  AmbientLight,
  PointLight,
  PointLightHelper,
  Object3D,
} from "https://cdnjs.cloudflare.com/ajax/libs/three.js/0.172.0/three.module.min.js";

export default class Light extends Object3D {
  point = null;
  ambient = null;

  constructor() {
    super();
    this.ambient = new AmbientLight(0xffffff);
    this.point = new PointLight(0xffffff);
    this.point.position.set(0, 11, 10);
    this.add(this.point, this.ambient);
  }
  getPointLight() {
    return this.point;
  }
}
