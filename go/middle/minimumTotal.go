package main

import "math"

func minimumTotal(triangle [][]int) int {
	dp := make([]int, len(triangle[len(triangle)-1]))
	for i := range triangle {
		for k := len(triangle[i]) - 1; k >= 0; k-- {
			if k == 0 {
				dp[k] = dp[k] + triangle[i][k]
			} else if k == len(triangle[i])-1 {
				dp[k] = dp[k-1] + triangle[i][k]
			} else {
				dp[k] = min(dp[k-1], dp[k]) + triangle[i][k]
			}
		}
	}
	rs := math.MaxInt
	for i := range dp {
		rs = min(rs, dp[i])
	}
	return rs
}
