class OrderedStream {
  private stream: string[];
  private ptr: number;
  constructor(n: number) {
    this.stream = new Array<string>(n);
    this.stream.fill("");
    this.ptr = 0;
  }

  insert(idKey: number, value: string): string[] {
    const rs: string[] = [];
    this.stream[idKey - 1] = value;
    while (this.ptr < this.stream.length && this.stream[this.ptr]! != "") {
      rs.push(this.stream[this.ptr]);
      this.ptr++;
    }
    return rs;
  }
}
