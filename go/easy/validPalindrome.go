package main

func checkPalindrome(s string, left int, right int, canRemove bool) bool {
	for left < right {
		if s[right] == s[left] {
			right--
			left++
			continue
		} else if canRemove {
			return checkPalindrome(s, left+1, right, false) || checkPalindrome(s, left, right-1, false)
		} else {
			return false
		}
	}
	return true
}

func validPalindrome(s string) bool {
	return checkPalindrome(s, 0, len(s)-1, true)
}
