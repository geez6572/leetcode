package main

func isPossibleToSplit(nums []int) bool {
	m := make([]int, 101)
	for _, v := range nums {
		m[v] = m[v] + 1
		if m[v] >= 3 {
			return false
		}
	}
	return true
}
