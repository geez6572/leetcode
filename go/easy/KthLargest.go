package main

import "sort"

type KthLargest struct {
	nums  []int
	index int
}

func Constructor(k int, nums []int) KthLargest {
	var el KthLargest
	sort.Ints(nums)
	el.nums = nums
	el.index = k
	return el
}

func (this *KthLargest) Add(val int) int {
	this.nums = append(this.nums, val)
	index := len(this.nums) - 1
	for index > 0 && this.nums[index-1] > val {
		this.nums[index] = this.nums[index-1]
		index--
	}
	this.nums[index] = val
	return this.nums[len(this.nums)-this.index]
}
