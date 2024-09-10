package main

func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {
	var pre *TreeNode = nil
	var rs *TreeNode = nil
	var recur func(node *TreeNode)
	recur = func(node *TreeNode) {
		if node == nil {
			return
		}
		recur(node.Left)
		if pre == p {
			rs = node
			return
		}
		pre = node
		recur(node.Right)
	}
	recur(root)
	return rs
}
