package main

func diStringMatch(s string) []int {
	rs := make([]int, len(s)+1)
	left := 0
	right := len(rs) - 1
	for i, v := range s {
		if v == 'I' {
			rs[i] = left
			left++
		} else {
			rs[i] = right
			right--
		}
	}
	rs[len(rs)-1] = left
	return rs
}
