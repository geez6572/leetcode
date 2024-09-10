package main

var (
	rs  *TreeNode = nil
	cur *TreeNode = nil
)

func recur(root *TreeNode) {
	if root == nil {
		return
	}
	recur(root.Left)
	if rs == nil {
		rs = root
		cur = rs
	} else {
		cur.Right = root
		cur = cur.Right
	}
	recur(root.Right)
}

func increasingBST(root *TreeNode) *TreeNode {
	recur(root)
	return rs
}
