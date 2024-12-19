package main

import "fmt"

func takeCharacters(s string, k int) int {
	if k == 0 {
		return 0
	}
	if 3*k > len(s) {
		return -1
	}
	s2b := []byte(s + s)
	diff := 3
	v := make([]int, 3)
	for i := range v {
		v[i] = k
	}
	left := 0
	right := 0
	for right < len(s2b) && diff > 0 {
		if s2b[right] >= 'a' && s2b[right] <= 'c' {
			v[s2b[right]-'a']--
			if v[s2b[right]-'a'] == 0 {
				diff--
			}
		}
		right++
	}
	if diff > 0 {
		return -1
	}
	rs := right - left
	for left < right {
		if s2b[left] >= 'a' && s2b[left] <= 'c' {
			v[s2b[left]-'a']++
			if v[s2b[left]-'a'] == 1 {
				for right < len(s2b) && s2b[right] != s2b[left] {
					if s2b[right] >= 'a' && s2b[right] <= 'c' {
						v[s2b[right]-'a']--
					}
					right++
				}
				if right == len(s2b) {
					break
				}
				v[s2b[right]-'a']--
				right++
			}
		}
		left++
		if left != 0 && right < len(s) {
			continue
		}
		rs = min(rs, right-left)
	}
	if rs > len(s) {
		return -1
	}
	return rs
}

func takeCharacters2(s string, k int) int {
	s2b := []byte(s)
	diff := 3
	left := 0
	right := 0
	m := make(map[byte]int)
	m['a'] = k
	m['b'] = k
	m['c'] = k
	for right < len(s2b) && diff > 0 {
		if _, e := m[s2b[right]]; e {
			m[s2b[right]]--
			if m[s2b[right]] == 0 {
				diff--
			}
		}
		right++
	}
	if diff > 0 {
		return -1
	}
	rs := right - left
	m['a'] = k
	m['b'] = k
	m['c'] = k
	diff = 3
	left = len(s) - 1
	right = len(s) - 1
	for left >= 0 && diff > 0 {
		if _, e := m[s2b[left]]; e {
			m[s2b[left]]--
			if m[s2b[left]] == 0 {
				diff--
			}
		}
		left--
	}
	rs = min(rs, right-left)

	m['a'] = k
	m['b'] = k
	m['c'] = k
	for i := range s {
		if _, e := m[s[i]]; e {
			m[s[i]]--
		}
	}
	left = 1
	right = len(s) + 1
	diff = 0
	s2b = append(s2b, []byte(s)...)
	for left < len(s) && right < len(s2b) {
		if diff == 0 {
			if _, e := m[s2b[left]]; e {
				m[s2b[left]]++
				if m[s2b[left]] == 1 {
					diff++
				}
			}
			left++
		} else {
			if _, e := m[s2b[right]]; e {
				m[s2b[right]]--
				if m[s2b[right]] == 0 {
					diff--
				}
			}
			right++
		}
		if diff == 0 {
			rs = min(rs, right-left)
		}
	}
	return rs
}

func takeCharacters3(s string, k int) int {
	l := len(s)
	rs := l
	m := make([]int, 3)
	for i := range s {
		m[s[i]-'a']++
	}
	if m[0] < k || m[1] < k || m[2] < k {
		return -1
	}
	left := 0
	right := 0
	for right < len(s) {
		m[s[right]-'a']--
		for left < right && (m[0] < k || m[1] < k || m[2] < k) {
			m[s[left]-'a']++
			left++
		}

		if !(m[0] < k || m[1] < k || m[2] < k) {
			rs = min(rs, l-(right-left))
		}
	}
	return rs
}

func main() {
	rs := takeCharacters2("ccbcac", 1)
	fmt.Println(rs)
}
