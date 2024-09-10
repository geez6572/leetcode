package main

func searchInsert(nums []int, target int) int {
	left := 0
	right := len(nums) - 1
	for left < right {
		mid := left + (right-left)/2
		if nums[mid] > target {
			right = mid - 1
		} else if nums[mid] == target {
			return mid
		} else {
			left = mid + 1
		}
	}
	if nums[left] > target {
		return left - 1
	} else if nums[left] == target {
		return left
	} else {
		return left + 1
	}
}
