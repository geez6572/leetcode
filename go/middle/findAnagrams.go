package main

func findAnagrams(s string, p string) []int {
	rs := []int{}
	if len(s) < len(p) {
		return rs
	}
	m := [26]int{}
	i := 0
	for i < len(p) {
		m[p[i]-'a']++
		m[s[i]-'a']--
	}

	for k := range m {
		if m[k] != 0 {
			break
		}
		if k == len(m)-1 {
			rs = append(rs, 0)
		}
	}
	start := 0
	for i < len(s) {
		m[s[start]-'a']++
		m[s[i]-'a']--
		start++
		i++
		for k := range m {
			if m[k] != 0 {
				break
			}
			if k == len(m)-1 {
				rs = append(rs, start)
			}
		}
	}
	return rs
}
