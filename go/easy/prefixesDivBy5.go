package main

func prefixesDivBy5(nums []int) []bool {
	rs := make([]bool, len(nums))
	cur := 0
	for i, v := range nums {
		cur = (cur << 1) + v
		if cur%5 == 0 {
			rs[i] = true
		} else {
			rs[i] = false
		}
	}
	return rs
}
