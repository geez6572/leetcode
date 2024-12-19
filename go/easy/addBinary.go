package main

func addBinary(a string, b string) string {
	ai := len(a) - 1

	bi := len(b) - 1
	var flag byte = 0
	var rs string
	for ai >= 0 && bi >= 0 {
		cur := a[ai] - '0' + a[bi] - '0' + flag
		if cur > 1 {
			flag = 1
		} else {
			flag = 0
		}
		rs = string((cur%2)+'0') + rs
		ai--
		bi--
	}
	for ai >= 0 {
		cur := a[ai] - '0' + flag
		if cur > 1 {
			flag = 1
		} else {
			flag = 0
		}
		rs = string((cur%2)+'0') + rs
		ai--
	}
	for bi >= 0 {
		cur := a[bi] - '0' + flag
		if cur > 1 {
			flag = 1
		} else {
			flag = 0
		}
		rs = string((cur%2)+'0') + rs
		bi--
	}
	if flag > 0 {
		rs = string('1') + rs
	}
	return rs
}
