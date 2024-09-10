package main

func dominantIndex(nums []int) int {
	maxi := 0
	for i := range nums {
		if nums[maxi] < nums[i] {
			maxi = i
		}
	}
	for i, v := range nums {
		if i != maxi && v*2 > nums[maxi] {
			return -1
		}
	}
	return maxi
}
