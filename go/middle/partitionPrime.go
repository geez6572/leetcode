package main

func partition(s string) [][]string {
	rs := make([][]string, 0)
	cur := make([]string, 0)
	check := func(left, right int) bool {
		for left < right {
			if s[left] != s[right] {
				return false
			}
		}
		return true
	}
	var recur func(left, right int)
	recur = func(left, right int) {
		if left > right {
			rs = append(rs, append([]string{}, cur...))
			return
		}
		for i := left; i <= right; i++ {
			if check(left, i) {
				cur = append(cur, ""+s[left:i+1])
				recur(i+1, right)
				cur = cur[:len(cur)-1]
			}
		}
	}
	recur(0, len(s)-1)
	return rs
}
