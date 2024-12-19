class List {
  val: number;
  id: number;
  next: List | null = null;
  constructor(val: number, id: number) {
    this.val = val;
    this.id = id;
  }
}

function findWinningPlayer(skills: number[], k: number): number {
  if (skills.length == 2) {
    if (skills[0] > skills[1]) {
      return 0;
    }
    return 1;
  }
  const dummy = new List(0, 0);
  let travel = dummy;
  for (let i = 0; i < skills.length; i++) {
    travel.next = new List(skills[i], i);
    travel = travel.next;
  }
  let count = 0;
  let continus = 0;
  while (continus < k && count < skills.length - 1) {
    const l1 = dummy.next;
    if (l1 == null) {
      break;
    }
    dummy.next = l1.next;
    const l2 = dummy.next;
    if (l2 == null) {
      break;
    }
    dummy.next = l2.next;
    if (l1.val > l2.val) {
      continus++;
      l1.next = dummy.next;
      dummy.next = l1;
      travel.next = l2;
      travel = l2;
    } else {
      continus = 1;
      l2.next = dummy.next;
      dummy.next = l2;
      travel.next = l1;
      travel = l1;
    }
    count++;
  }
  return dummy.next!.id;
}

function findWinningPlayer(skills: number[], k: number): number {
  let max = skills[0];
  let maxId = 0;
  let continus = 0;
  for (let i = 1; i < skills.length && continus < k; i++) {
    if (skills[i] > max) {
      continus = 1;
      max = skills[i];
      maxId = i;
    } else {
      continus++;
    }
  }
  return maxId;
}
