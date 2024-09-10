package main

func firstMissingPositive(nums []int) int {
	index := 0
	for index < len(nums) {
		if nums[index] <= 0 || nums[index] == 1+index {
			index++
			continue
		}
		rightPos := nums[index] - 1
		if rightPos < len(nums) && nums[rightPos] != nums[index] {
			nums[index], nums[rightPos] = nums[rightPos], nums[index]
		} else {
			index++
		}
	}
	index = 0
	for index < len(nums) && index+1 == nums[index] {
		index++
	}
	return index + 1
}
