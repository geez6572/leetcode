package main

import "strings"

func uncommonFromSentences(s1 string, s2 string) []string {
	m := make(map[string]int)
	split1 := strings.Split(s1, " ")
	split2 := strings.Split(s2, " ")
	for i := range split1 {
		if _, exist := m[split1[i]]; exist {
			m[split1[i]]++
		} else {
			m[split1[i]] = 1
		}
	}
	for i := range split2 {
		if _, exist := m[split2[i]]; exist {
			m[split2[i]]++
		} else {
			m[split2[i]] = 1
		}
	}

	var rs []string
	for k, v := range m {
		if v == 1 {
			rs = append(rs, k)
		}
	}
	return rs
}
