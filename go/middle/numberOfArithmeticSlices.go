package main

func numberOfArithmeticSlices(nums []int) int {
	if len(nums) < 3 {
		return 0
	}
	rs := 0
	dp := make([]int, len(nums))
	for i := 2; i < len(nums); i++ {
		if nums[i]-nums[i-1] == nums[i-1]-nums[i-2] {
			if dp[i-1] == 0 {
				dp[i] = 1
			} else {
				dp[i] = dp[i-1] * 2
			}
		}
		rs += dp[i]
	}
	return rs
}
