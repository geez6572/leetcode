package main

func toLowerCase(s string) string {
	var rs string
	for i := range s {
		if s[i] >= 'A' && s[i] <= 'Z' {
			rs += string('a' + s[i] - 'A')
		}
	}
	return rs
}
