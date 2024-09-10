package main

func uniqueMorseRepresentations(words []string) int {
	ms := [26]string{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}
	mapping := map[string]bool{}
	for _, word := range words {
		var cur string
		for _, c := range word {
			cur = cur + ms[c-'a']
		}
		if _, exist := mapping[cur]; !exist {
			mapping[cur] = true
		}
	}
	return len(mapping)
}
