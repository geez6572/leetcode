package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeList(a, b *ListNode) *ListNode {
	rs := new(ListNode)
	cur := rs
	for a != nil && b != nil {
		if a.Val < b.Val {
			temp := a.Next
			a.Next = cur.Next
			cur.Next = a
			a = temp
		} else {
			temp := b.Next
			b.Next = cur.Next
			cur.Next = b
			b = temp
		}
		cur = cur.Next
	}
	if a != nil {
		cur.Next = a
	}
	if b != nil {
		cur.Next = b
	}
	return rs.Next
}

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	slow := head
	fast := head
	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	mid := slow.Next
	slow.Next = nil
	left := sortList(head)
	right := sortList(mid)
	return mergeList(left, right)
}
