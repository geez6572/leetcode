package main

type CBTInserter struct {
	arr []*TreeNode
}

func Constructor(root *TreeNode) CBTInserter {
	var rs CBTInserter
	rs.arr = []*TreeNode{nil}
	queue := []*TreeNode{root}
	for len(queue) > 0 {
		curLen := len(queue)
		for i := 0; i < curLen; i++ {
			cur := queue[0]
			queue = queue[1:]
			rs.arr = append(rs.arr, cur)
			if cur.Left != nil {
				queue = append(queue, cur.Left)
			}
			if cur.Right != nil {
				queue = append(queue, cur.Right)
			}
		}
	}
	return rs
}

func (this *CBTInserter) Insert(v int) int {
	temp := &TreeNode{Val: v}
	this.arr = append(this.arr, temp)
	parent := this.arr[(len(this.arr)-1)/2]
	if parent.Left == nil {
		parent.Left = temp
	} else {
		parent.Right = temp
	}
	return parent.Val
}

func (this *CBTInserter) Get_root() *TreeNode {
	return this.arr[1]
}
