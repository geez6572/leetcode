package main

func mincostTickets(days []int, costs []int) int {
	dp := make([][]int, len(days))
	for i := range dp {
		dp[i] = make([]int, 31)
		for k := range dp[i] {
			dp[i][k] = 10000
		}
	}

	dp[0][1] = costs[0]
	dp[0][7] = costs[1]
	dp[0][30] = costs[2]
	preMin := costs[0]
	for i := 1; i < len(dp); i++ {
		diff := days[i] - days[i-1]
		dp[i][1] = costs[0] + dp[i-1][1]
		dp[i][7] = costs[1] + dp[i-1][1]
		dp[i][30] = costs[2] + preMin
		curMin := min(dp[i][1], min(dp[i][7], dp[i][30]))
		for k := 1; k < 30; k++ {
			if k+diff > 30 {
				continue
			} else if k == 1 {
				dp[i][k] = min(dp[i-1][k+diff], dp[i][k])
			} else if k == 7 {
				dp[i][k] = min(dp[i-1][k+diff], dp[i][k])
			} else {
				dp[i][k] = dp[i-1][k+diff]
			}
			curMin = min(curMin, dp[i][k])
		}
		preMin = curMin
	}
	return preMin
}

func mincostTickets2(days []int, costs []int) int {
	dp := make([]int, days[len(days)-1]+1)
	for i, k := 1, 0; i < len(dp) && k < len(days); i++ {
		dp[i] = dp[i-1]
		if i == days[k] {
			dp[i] = dp[i-1] + costs[0]
			dp[i] = min(dp[max(0, i-7)]+costs[1], dp[i])
			dp[i] = min(dp[max(0, i-30)]+costs[2], dp[i])
			k++
		}
	}
	return dp[len(dp)-1]
}
