import {
  BoxGeometry,
  MeshMatcapMaterial,
  Mesh,
  Box3,
} from "https://cdnjs.cloudflare.com/ajax/libs/three.js/0.172.0/three.module.min.js";

const HEIGHT = 6;

export default class Player extends Mesh {
  constructor(x, y, z, name, idName) {
    const geo = new BoxGeometry(1, 1, HEIGHT);
    const material = new MeshMatcapMaterial({ color: 0xffffff });
    super(geo, material);
    this.position.x = x;
    this.position.y = y;
    this.position.z = z;
    this.height = HEIGHT;
    this.score = 0;
    this.box = new Box3().setFromObject(this);
    this.name = name;
    this.idName = idName;
    this.printName();
  }

  getBox() {
    return this.box;
  }

  getHeight() {
    return HEIGHT;
  }

  touchBox(box3) {
    return this.box.intersectsBox(box3);
  }

  updateBox() {
    this.box.setFromObject(this);
  }

  getScore() {
    return this.score;
  }
  printName() {
    document.getElementById(this.idName).textContent = `${this.name}`;
  }
  printScore(id) {
    document.getElementById(id).textContent = `${this.score}`;
  }
}
