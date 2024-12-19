package main

func numberOfPoints(nums [][]int) int {
	diff := make([]int, 110)
	for i := range nums {
		diff[nums[i][0]]++
		diff[nums[i][1]+1]--
	}
	rs := 0
	for i := 1; i < len(diff); i++ {
		diff[i] += diff[i-1]
		if diff[i] != 0 {
			rs++
		}
	}
	return rs
}
