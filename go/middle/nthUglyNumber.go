package main

func nthUglyNumber(n int) int {
	dp := make([]int, n+1)
	dp[0] = 1
	i2, i3, i5 := 0, 0, 0
	for i := 1; i <= n; i++ {
		n2, n3, n5 := dp[i2]*2, dp[i3]*3, dp[i5]*5
		dp[i] = min(n2, min(n3, n5))
		if dp[i] == n2 {
			i2++
		}
		if dp[i] == n3 {
			i3++
		}
		if dp[i] == n5 {
			i5++
		}
	}
	return dp[n]
}
