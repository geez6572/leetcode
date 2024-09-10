package main

func largeGroupPositions(s string) [][]int {
	left := 0
	right := 0
	l := len(s)
	rs := [][]int{}
	for right < l {
		for right < l && s[right] == s[left] {
			right++
		}
		if right-left >= 3 {
			rs = append(rs, []int{left, right - 1})
		}
		left = right
	}
	return rs
}
