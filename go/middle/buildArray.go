package main

func buildArray(target []int, n int) []string {
	cur := 0
	rs := make([]string, 0)
	i := 1
	for i = 1; i <= n && cur < len(target); i++ {
		rs = append(rs, "Push")
		if i != target[cur] {
			rs = append(rs, "Pop")
			cur--
		}
		cur++
	}
	for i <= n {
		rs = append(rs, "Push")
		rs = append(rs, "Pop")
		i++
	}
	return rs
}
