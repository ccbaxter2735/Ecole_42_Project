import {
  BoxGeometry,
  MeshMatcapMaterial,
  Mesh,
  Box3,
} from "https://cdnjs.cloudflare.com/ajax/libs/three.js/0.172.0/three.module.min.js";

export default class Ball extends Mesh {
  constructor(x, y, z) {
    const geo = new BoxGeometry(1, 1, 1);
    const material = new MeshMatcapMaterial({ color: 0xffffff });
    super(geo, material);
    this.position.x = x;
    this.position.y = y;
    this.position.z = z;
    this.box = new Box3().setFromObject(this);
  }
  getBox() {
    return this.box;
  }
  touchBox(box3) {
    return this.box.intersectsBox(box3);
  }
  updateBox() {
    this.box.setFromObject(this);
  }
}
