package main

func maxProduct(words []string) int {
	m := make([]int, len(words))
	for i := range words {
		for k := range words[i] {
			m[i] = m[i] | (1 << (words[i][k] - 'a'))
		}
	}
	rs := 0
	for i := 0; i < len(words); i++ {
		for k := i + 1; k < len(words); k++ {
			if m[i]&m[k] == 0 {
				rs = max(rs, len(words[i])*len(words[k]))
			}
		}
	}
	return rs
}
