package main

import "slices"

func hIndex(citations []int) int {
	slices.Sort(citations)
	rs := 0
	for i := 0; i < len(citations)-1; i++ {
		h := len(citations) - i
		if citations[i] >= h {
			rs = h
			break
		}
	}
	return rs
}
