package main

import (
	"sort"
)

func countWays(nums []int) int {
	rs := 0
	sort.Ints(nums)
	for i := range nums {
		if (nums[i] < (i + 1)) && ((i == len(nums)-1) || (i+1) < nums[i+1]) {
			rs++
		}
	}
	if nums[0] > 0 {
		rs++
	}
	return rs
}
