package main

func maximizeSum(nums []int, k int) int {
	m := nums[0]
	for _, v := range nums {
		if v > m {
			m = v
		}
	}
	return m*k + k*(k-1)/2
}
