package main

type BSTIterator struct {
	elements []int
	cur      int
}

func Constructor(root *TreeNode) BSTIterator {
	var rs BSTIterator
	rs.elements = append(rs.elements, -1)
	var recur func(node *TreeNode)
	recur = func(node *TreeNode) {
		if node == nil {
			return
		}
		recur(node.Left)
		rs.elements = append(rs.elements, node.Val)
		recur(node.Right)
	}
	return rs
}

func (this *BSTIterator) Next() int {
	if this.HasNext() {
		this.cur = this.cur + 1
		return this.elements[this.cur]
	}
	return -1
}

func (this *BSTIterator) HasNext() bool {
	return this.cur < len(this.elements)-1
}
