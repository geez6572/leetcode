package main

func longestCommonSubsequence(text1 string, text2 string) int {
	dp := make([][]int, len(text1)+1)
	for i := range dp {
		dp[i] = make([]int, len(text2)+1)
	}
	for i := 1; i < len(dp); i++ {
		for k := 1; k < len(dp[i]); k++ {
			if text1[i-1] == text2[k-1] {
				dp[i][k] = dp[i-1][k-1] + 1
			} else {
				dp[i][k] = max(dp[i-1][k], dp[i][k-1])
			}
		}
	}
	return dp[len(dp)-1][len(dp[0])-1]
}
