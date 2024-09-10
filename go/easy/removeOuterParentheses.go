package main

import "strings"

func removeOuterParentheses(s string) string {
	var rs string
	start := 0
	cur_left := 0
	cur_right := 0
	for i := range s {
		if s[i] == '(' {
			cur_left++
		} else {
			cur_right++
		}
		if cur_left > 1 && cur_left != cur_right {
			rs = rs + string(s[i])
		}
		if cur_left == cur_right {
			cur_left = 0
			cur_right = 0
		}
	}
	return rs
}
