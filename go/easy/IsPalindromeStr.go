package main

func isAl(c uint8) bool {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')
}

func toLow(c uint8) uint8 {
	if c >= 'A' && c <= 'Z' {
		c = 'a' + c - 'A'
	}
	return c
}

func isPalindromeStr(s string) bool {
	left := 0
	right := len(s) - 1
	for left < right {
		for left < right && !isAl(s[left]) {
			left++
		}
		for left < right && !isAl(s[right]) {
			right--
		}
		if toLow(s[left]) != toLow(s[right]) {
			return false
		}
		left++
		right--
	}
	return true
}
