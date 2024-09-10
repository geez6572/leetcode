package main

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	l1 := 0
	l2 := 0
	dummy1 := headA
	dummy2 := headB
	for dummy1 != nil {
		l1 = l1 + 1
		dummy1 = dummy1.Next
	}
	for dummy2 != nil {
		l2 = l2 + 1
		dummy2 = dummy2.Next
	}
	if l1 > l2 {
		for i := 0; i < l1-l2; i = i + 1 {
			headA = headA.Next
		}
	}
	if l1 < l2 {
		for i := 0; i < l2-l1; i = i + 1 {
			headB = headB.Next
		}
	}
	for headA != nil && headB != nil {
		if headA == headB {
			return headA
		}
		headA = headA.Next
		headB = headB.Next
	}
	return nil
}
