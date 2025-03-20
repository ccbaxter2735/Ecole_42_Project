import {
  BoxGeometry,
  MeshMatcapMaterial,
  Mesh,
  Group,
} from "https://cdnjs.cloudflare.com/ajax/libs/three.js/0.172.0/three.module.min.js";

export default class MiddleBar extends Group {
  constructor() {
    super();
    const geo = new BoxGeometry(1, 0.3, 1);
    const material = new MeshMatcapMaterial({ color: 0xffffff });
    let z = -14;
    for (let i = 0; i < 15; i++) {
      const cube = new Mesh(geo, material);
      cube.position.z = z;
      cube.position.y = -0.7;
      z += 2;
      this.add(cube);
    }
  }
}
