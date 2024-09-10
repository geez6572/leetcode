package main

func isMonotonic(nums []int) bool {
	l := len(nums)
	if l <= 2 {
		return true
	}
	pre := 0
	cur := 0
	for cur < len(nums) {
		if nums[cur] == nums[pre] {
			cur++
		} else {
			if (nums[cur]-nums[pre] > 0) != (nums[l-1]-nums[0] > 0) {
				return false
			}
			pre = cur
		}
	}
	return true
}
