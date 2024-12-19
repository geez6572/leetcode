package main

func averageOfSubtree(root *TreeNode) int {
	rs := 0
	var recur func(node *TreeNode) (int, int)
	recur = func(node *TreeNode) (int, int) {
		if node == nil {
			return 0, 0
		}
		lnodes, lsum := recur(node.Left)
		rnodes, rsum := recur(node.Right)
		curNodes := lnodes + rnodes + 1
		cursum := lsum + rsum + node.Val
		if cursum/curNodes == node.Val {
			rs++
		}
		return curNodes, cursum
	}
	recur(root)
	return rs
}
