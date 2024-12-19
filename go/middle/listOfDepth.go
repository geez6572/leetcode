package main

func listOfDepth(tree *TreeNode) []*ListNode {
	if tree == nil {
		return []*ListNode{}
	}
	queue := make([]*TreeNode, 0)
	rs := make([]*ListNode, 0)
	rs = append(rs, &ListNode{Val: tree.Val})
	for len(queue) > 0 {
		n := len(queue)
		cur := new(ListNode)
		travel := cur
		for i := 0; i < n; i++ {
			node := queue[0]
			queue = queue[1:]
			travel.Next = &ListNode{Val: node.Val}
			travel = travel.Next
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}
		rs = append(rs, cur)
	}
	return rs
}
