package main

func search(nums []int, target int) int {
	left := 0
	right := len(nums) - 1
	for left <= right {
		mid := left + (right-left)>>1
		if nums[mid] == target {
			return mid
		}
		if nums[mid] < nums[len(nums)-1] {
			if nums[mid] < target && target <= nums[len(nums)-1] {
				left = mid + 1
			} else {
				right = mid - 1
			}
		} else {
			if nums[mid] > target && target >= nums[0] {
				right = mid - 1
			} else {
				left = mid + 1
			}
		}
	}
	return -1
}
