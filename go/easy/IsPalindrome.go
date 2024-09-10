package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func isPalindrome(head *ListNode) bool {
	var arr []int
	var right int = -1
	var left int = 0
	for head != nil {
		arr = append(arr, head.Val)
		head = head.Next
		right++
	}
	if right == -1 {
		return false
	}
	for right > left {
		if arr[left] != arr[right] {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println("fff")
}
