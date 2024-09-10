package main

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	len1 := 0
	len2 := 0
	for i := l1; i != nil; i = i.Next {
		len1++
	}
	for i := l2; i != nil; i = i.Next {
		len2++
	}
	if len1 < len2 {
		l1, l2 = l2, l1
		len1, len2 = len2, len1
	}
	var recur func(node1, node2 *ListNode, len1, len2 int) int
	recur = func(node1, node2 *ListNode, leng1, leng2 int) int {
		if node1 == nil || node2 == nil {
			return 0
		}
		var val int
		if leng1 > leng2 {
			val = node1.Val + recur(node1.Next, node2, leng1-1, leng2)
		} else if leng1 == leng2 {
			val = node1.Val + node2.Val + recur(node1.Next, node2.Next, leng1-1, leng2-1)
		} else {
			val = node2.Val + recur(node1, node2.Next, leng1, leng2-1)
		}
		node1.Val = val % 10
		if val >= 10 {
			return 1
		}
		return 0
	}
	front := recur(l1, l2, len1, len2)
	if front == 1 {
		rs := &ListNode{Val: 1, Next: l1}
		return rs
	}
	return l1
}
