package main

func deleteAndEarn(nums []int) int {
	m := map[int]int{}
	for i := range nums {
		m[nums[i]]++
	}
}
