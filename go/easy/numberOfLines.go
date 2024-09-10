package main

func numberOfLines(widths []int, s string) []int {
	line := 0
	cur := 0
	l := len(s)
	i := 0
	for i < l {
		line++
		cur = 0
		for i < l && cur+widths[s[i]-'a'] <= 100 {
			cur += widths[s[i]-'a']
			i++
		}
	}
	rs := []int{line, cur}
	return rs
}
