package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reorderList(head *ListNode) {
	// split list in tow equal length
	if head == nil || head.Next == nil {
		return
	}
	slow := head
	fast := head
	for fast.Next != nil && fast.Next.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}

	other := slow.Next
	slow.Next = nil
	// reverse other list
	var pre *ListNode = nil
	for other != nil {
		next := other.Next
		other.Next = pre
		pre = other
		other = next
	}

	for pre != nil {
		next := pre.Next
		pre.Next = head.Next
		head.Next = pre
		head = pre.Next
		pre = next
	}
}
