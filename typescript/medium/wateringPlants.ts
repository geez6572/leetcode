function wateringPlants(plants: number[], capacity: number): number {
  let index = 0;
  let curCap = capacity;
  let rs = 0;
  for (let i = 0; i < plants.length; i++) {
    if (curCap == capacity) {
      rs += i + 1;
      rs += Math.ceil(plants[i] / capacity);
      curCap = plants[i] % capacity;
    } else {
    }
  }
}
