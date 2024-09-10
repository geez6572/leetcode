package main

func validNumber(s string) bool {
	left := 0
	right := len(s) - 1
	for left <= right && s[left] == ' ' {
		left++
	}
	for left <= right && s[right] == ' ' {
		right--
	}
	if left <= right && (s[left] == '+' || s[left] == '-') {
		left++
	}
	if left > right {
		return false
	} else if left == right {
		return s[left] >= '0' && s[left] <= '9'
	}
	dotIndex := -1
	eIndex := -1
	syIndex := -1
	start := left
	for left <= right {
		if s[left] >= '0' && s[left] <= '9' {
			left++
			continue
		} else if s[left] == 'e' || s[left] == 'E' {
			if eIndex == -1 && left != right && left != start {
				eIndex = left
			} else {
				return false
			}
		} else if s[left] == '.' {
			if dotIndex == -1 {
				dotIndex = left
			} else {
				return false
			}
		} else if s[left] == '+' || s[left] == '-' {
			if syIndex == -1 && eIndex != -1 && left != right {
				syIndex = left
			} else {
				return false
			}
		} else {
			return false
		}
		left++
	}
	if dotIndex != -1 && eIndex != -1 {
		if dotIndex > eIndex || (dotIndex == start && eIndex == dotIndex+1) {
			return false
		}
	}
	return true
}
