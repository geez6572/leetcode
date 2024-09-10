package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if k <= 1 {
		return head
	}
	arr := []*ListNode{}
	travel := head
	for travel != nil {
		arr = append(arr, travel)
		travel = travel.Next
	}
	reverse := func(left, right int) {
		for left < right {
			temp := arr[left]
			arr[left] = arr[right]
			arr[right] = temp
			left++
			right--
		}
	}
	for i := 0; i < len(arr) && i+k-1 < len(arr); i = i + k {
		reverse(i, i+k-1)
	}
	for i := range arr {
		if i == len(arr)-1 {
			arr[i].Next = nil
			break
		}
		arr[i].Next = arr[i+1]
	}
	return arr[0]
}

func reverseKGroup2(head *ListNode, k int) *ListNode {
	if k <= 1 {
		return head
	}
	rs := new(ListNode)
	rs.Next = head
	travel := rs
	last := travel.Next
	travel.Next = nil
	for last != nil {
		left := last
		for i := 0; i < k-1 && last != nil; i++ {
			last = last.Next
		}
		if last == nil {
			break
		}
		nextTravel := left
		for i := 0; i < k; i++ {
			temp := left
			left = left.Next
			temp.Next = travel.Next
			travel.Next = temp
		}
		last = left
		travel = nextTravel
	}
	return rs.Next
}

func main() {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	head.Next.Next.Next = &ListNode{Val: 4}
	head.Next.Next.Next.Next = &ListNode{Val: 5}
	reverseKGroup2(head, 2)
}
