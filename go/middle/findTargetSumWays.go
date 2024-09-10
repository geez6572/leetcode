package main

import (
	"math"
	"slices"
)

func findTargetSumWays(nums []int, target int) int {
	var recur func(last, cur int) int
	recur = func(last, cur int) int {
		if last == 0 {
			rs := 0
			if nums[last] == cur {
				rs++
			}
			if nums[last] == -cur {
				rs++
			}
			return rs
		}
		return recur(last-1, cur+nums[last]) + recur(last-1, cur-nums[last])
	}
	return recur(len(nums)-1, target)
}

func findTargetSumWays_dp(nums []int, target int) int {
	abs := func(x int) int {
		if x < 0 {
			return -x
		}
		return x
	}
	sum := 0
	for _, v := range nums {
		sum += v
	}
	x := sum + target
	if x%2 == 1 || sum < abs(target) {
		return 0
	}
	x = x / 2
	dp := make([]int, x+1)
	dp[0] = 1
	for i := 0; i < len(nums); i++ {
		for k := len(dp) - 1; k >= nums[i]; k-- {
			dp[k] = dp[k] + dp[k-nums[i]]
		}
	}
	return dp[len(dp)-1]
}
