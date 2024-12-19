package main

func longestContinuousSubstring(s string) int {
	if len(s) <= 1 {
		return len(s)
	}
	rs := 1
	cur := 0
	pre := 1
	for i := 1; i < len(s); i++ {
		cur = 1
		if s[i]-s[i-1] == 1 {
			cur += pre
		}
		rs = max(rs, cur)
		pre = cur
	}
	return rs
}
