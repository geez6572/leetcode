package main

func findKthLargest(nums []int, k int) int {
	rs := 0
	var quickSort func(left, right int)
	quickSort = func(left, right int) {
		if left > right {
			return
		}
		newLeft := left
		newRight := right
		split := nums[left]
		for left < right {
			for left < right && nums[right] > split {
				right--
			}
			if left < right {
				nums[left] = nums[right]
				left++
			}
			for left < right && nums[left] < split {
				left++
			}
			if left < right {
				nums[right] = nums[left]
				right--
			}
		}
		nums[left] = split
		if left == len(nums)-k {
			rs = nums[left]
			return
		} else if left < len(nums)-k {
			quickSort(left+1, newRight)
		} else {
			quickSort(newLeft, left-1)
		}
	}
	quickSort(0, len(nums)-1)
	return rs
}
