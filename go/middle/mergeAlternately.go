package main

func mergeAlternately(word1 string, word2 string) string {
	rs := make([]byte, len(word1)+len(word2))
	index := 0
	w1i := 0
	w2i := 0
	for w1i < len(word1) || w2i < len(word2) {
		if w1i < len(word1) {
			rs[index] = word1[w1i]
			index++
			w1i++
		}
		if w2i < len(word2) {
			rs[index] = word2[w2i]
			index++
			w2i++
		}
	}
	return string(rs)
}
