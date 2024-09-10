package main

func majorityElement(nums []int) int {
	count := 0
	cur := nums[0]
	for i := range nums {
		if nums[i] == cur {
			count++
		} else {
			count--
		}
		if count == 0 {
			count = 1
			cur = nums[i]
		}
	}
	return cur
}
