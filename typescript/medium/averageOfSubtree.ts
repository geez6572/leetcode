class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val == undefined ? 0 : val;
    this.left = left == undefined ? null : left;
    this.right = right == undefined ? null : right;
  }
}

function averageOfSubtree(root: TreeNode | null): number {
  let rs = 0;
  const recur = function (node: TreeNode | null): number[] {
    if (node == null) {
      return [0, 0];
    }
    const l = recur(node.left);
    const r = recur(node.right);
    const curSum = l[0] + r[0] + node.val;
    const curNodes = l[1] + r[1] + 1;
    if ((curSum / curNodes) == node.val) {
      rs++;
    }
    return [curSum, curNodes];
  };
  recur(root);
  return rs;
}

const root = new TreeNode(4);
root.left = new TreeNode(8);
root.right = new TreeNode(5);
root.right.right = new TreeNode(6);
root.left.left = new TreeNode(0);
root.left.right = new TreeNode(1);
const rs = averageOfSubtree(root);
console.log(rs);
