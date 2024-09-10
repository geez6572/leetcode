package main

import "sort"

func maxStrength(nums []int) int64 {
	if len(nums) == 1 {
		return int64(nums[0])
	}
	sort.Ints(nums)
	right := len(nums) - 1
	m := 0
	for right >= 0 && nums[right] > 0 {
		if m == 0 {
			m = nums[right]
		} else {
			m = m * nums[right]
		}
	}
	left := 0
	rs := m
	for left < right && nums[left] < 0 {
		rs = max(rs, rs*nums[left])
	}
	return int64(rs)
}
