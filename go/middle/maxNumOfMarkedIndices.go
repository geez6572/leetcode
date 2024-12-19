package main

import "sort"

func maxNumOfMarkedIndices(nums []int) int {
	if len(nums) <= 1 {
		return 0
	}
	sort.Ints(nums)
	left := 0
	right := len(nums) / 2
	rs := 0
	for left < len(nums)/2 && right < len(nums) {
		if nums[left]*2 <= nums[right] {
			rs += 2
			left++
			right++
		} else {
			right++
		}
	}
	return rs
}
