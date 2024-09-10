package main

func minFlipsMonoIncr(s string) int {
	dp := make([][]int, len(s))
	for i := range dp {
		dp[i] = make([]int, 2)
	}
	if s[0] == '0' {
		dp[0][0] = 0
		dp[0][1] = 1
	} else {
		dp[0][0] = 1
		dp[0][1] = 0
	}
	for i := 1; i < len(s); i++ {
		if s[i] == '0' {
			dp[i][0] = dp[i-1][0]
			dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1
		} else {
			dp[i][0] = dp[i-1][0] + 1
			dp[i][1] = min(dp[i-1][0], dp[i-1][1])
		}
	}
	return min(dp[len(dp)-1][0], dp[len(dp)-1][1])
}
