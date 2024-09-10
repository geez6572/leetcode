package main

func mergeNodes(head *ListNode) *ListNode {
	rs := new(ListNode)
	travel := rs
	cur := 0
	for head != nil {
		if head.Val == 0 {
			if cur != 0 {
				travel.Next = &ListNode{Val: cur, Next: nil}
				travel = travel.Next
			}
			cur = 0
		} else {
			cur += head.Val
		}
		head = head.Next
	}
	return rs.Next
}
