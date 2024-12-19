package main

func pathInZigZagTree(label int) []int {
	rs := []int{}
	start := 1
	for start*2 < label {
		start = start * 2
	}
	end := start*2 - 1
	for label > 0 {
		rs = append([]int{label}, rs...)
		label = end - (label - start)
		start = start / 2
		end = end / 2
	}
	return rs
}
