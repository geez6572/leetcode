package main

func scoreOfString(s string) int {
	rs := 0
	for i := 1; i < len(s); i++ {
		if s[i] > s[i-1] {
			rs += int(s[i] - s[i-1])
		} else {
			rs += int(s[i-1] - s[i])
		}
	}
	return rs
}
