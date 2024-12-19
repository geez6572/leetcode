package main

func shuffle(nums []int, n int) []int {
	rs := make([]int, len(nums))
	mid := len(nums) / 2
	for i := 0; i < len(rs); i++ {
		if i%2 == 0 {
			rs[i] = nums[i/2]
		} else {
			rs[i] = nums[mid+i/2]
		}
	}
	return rs
}
