package main

type RecentCounter struct {
	nums []int
}

func Constructor() RecentCounter {
	var rs RecentCounter
	rs.nums = make([]int, 0)
	return rs
}

func (this *RecentCounter) Ping(t int) int {
	this.nums = append(this.nums, t)
	left := 0
	for left < len(this.nums) && this.nums[left] < t-3000 {
		left++
	}
	this.nums = this.nums[left:]
	return len(this.nums)
}
