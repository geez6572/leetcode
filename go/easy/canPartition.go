package main

import "fmt"

func canPartition(nums []int) bool {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	if sum%2 == 1 {
		return false
	}
	dp := make([][]int, sum+1)
	for i := range dp {
		dp[i] = make([]int, len(nums)+1)
	}
	for i := 1; i < len(dp); i++ {
		for k := 1; k < len(dp[0]); k++ {
			if nums[k-1] <= i {
				dp[i][k] = max(dp[i-nums[k-1]][k-1]+nums[k-1], dp[i][k-1])
			} else {
				dp[i][k] = dp[i][k-1]
			}
		}
	}
	for i := range dp {
		for k := range dp[0] {
			fmt.Print(dp[i][k], " ")
		}
		fmt.Println()
	}
	return dp[len(dp)-1][len(dp[0])-1] == sum/2
}

func main() {
	nums := []int{1, 5, 11, 5}
	canPartition(nums)
}
