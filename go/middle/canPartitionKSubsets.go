package main

import "sort"

func canPartitionKSubsets(nums []int, k int) bool {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	if sum%k != 0 {
		return false
	}
	sort.Ints(nums)
	choosed := make([]bool, len(nums))
	var recur func(curIndex, curNum int)
	recur = func(curIndex, curNum int) {
		for i := curIndex; i < len(nums); i++ {
			if choosed[i] ||{
				continue
			}
		}
	}
}
