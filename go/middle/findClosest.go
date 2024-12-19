package main

func findClosest(words []string, word1 string, word2 string) int {
	last1 := -1
	last2 := -1
	rs := len(words)
	abs := func(v int) int {
		if v < 0 {
			return -v
		}
		return v
	}
	for i, v := range words {
		if v == word1 {
			last1 = i
		}
		if v == word2 {
			last2 = i
		}
		if last1 != -1 && last2 != -1 {
			rs = min(rs, abs(last1-last2))
		}
	}
	return rs
}
