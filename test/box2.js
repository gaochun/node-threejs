var THREE = require('../build/Debug/threejs');

var box2 = new THREE.Box2(1, 100);
console.log(box2);
console.log(box2.set);
console.log(box2.set(2, 200));
console.log(box2.isEmpty);
console.log(box2.isEmpty());
