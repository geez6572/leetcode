package main

import "fmt"

func checkInclusion(s1 string, s2 string) bool {
	if len(s2) < len(s1) {
		return false
	}
	m1 := [26]int{}
	diff := 0
	for i := range s1 {
		m1[s1[i]-'a']++
		if m1[s1[i]-'a'] == 1 {
			diff++
		}
	}
	left := 0
	right := 0
	for right-left+1 <= len(s1) {
		m1[s2[right]-'a']--
		if m1[s2[right]-'a'] == 0 {
			diff--
		} else if m1[s2[right]-'a'] == -1 {
			diff++
		}
		right++
	}
	if diff == 0 {
		return true
	}
	for right < len(s2) {
		m1[s2[left]-'a']++
		if m1[s2[left]-'a'] == 0 {
			diff--
		} else if m1[s2[left]-'a'] == 1 {
			diff++
		}
		m1[s2[right]-'a']--
		if m1[s2[right]-'a'] == 0 {
			diff--
		} else if m1[s2[right]-'a'] == -1 {
			diff++
		}
		if diff == 0 {
			return true
		}
		left++
		right++
	}
	return false
}

func main() {
	rs := checkInclusion("abcdxabcde", "abcdeabcdx")
	fmt.Println(rs)
}
