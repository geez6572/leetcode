package main

func massage(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	dp := make([]int, len(nums)+1)
	dp[0] = 0
	dp[1] = nums[0]
	for i := 2; i < len(dp); i = i + 1 {
		dp[i] = max(dp[i-1], dp[i-2]+nums[i-1])
	}
	return dp[len(dp)-1]
}
