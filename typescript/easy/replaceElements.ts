function replaceElements(arr: number[]): number[] {
  const stack = new Array<number>(1).fill(-1);
  for (let i = arr.length - 1; i >= 0; i--) {
    if (arr[i] >= stack[stack.length - 1]) {
      stack.push(arr[i]);
    }
  }
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === stack[stack.length - 1]) {
      stack.pop();
    }
    arr[i] = stack[stack.length - 1];
  }
  return arr;
}
