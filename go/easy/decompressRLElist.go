package main

func decompressRLElist(nums []int) []int {
	rs := []int{}
	for i := 0; i < len(nums); i = i + 2 {
		for k := 0; k < i; k++ {
			rs = append(rs, nums[i+1])
		}
	}
	return rs
}
