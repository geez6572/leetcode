function isPrefixOfWord(sentence: string, searchWord: string): number {
  let index = 0;
  let count = 0;
  while (index < sentence.length) {
    while (index < sentence.length && sentence[index] == " ") {
      index++;
    }
    let mIndex = 0;
    let flag = true;
    while (index < sentence.length && sentence[index] != " ") {
      if (
        mIndex < searchWord.length && sentence[index] != searchWord[mIndex]
      ) {
        flag = false;
      }
      index++;
      mIndex++;
    }
    count++;
    if (flag && mIndex >= searchWord.length) {
      return count;
    }
  }
  return -1;
}
