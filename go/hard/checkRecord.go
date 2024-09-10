package main

import "fmt"

func checkRecord(n int) int {
	if n == 1 {
		return 3
	}
	if n == 2 {
		return 8
	}
	dp := make([]int, n+1)
	dp[1] = 3
	dp[2] = 8
	for i := 3; i <= n; i++ {
		dp[i] = dp[i-1] + (dp[i-1] - (i - 1)) + (i-1)*2
	}

	return dp[n]
}

func main() {
	fmt.Println(checkRecord(2))
}
