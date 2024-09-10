package main

func isAlienSorted(words []string, order string) bool {
	ruler := make([]int, 26)
	for i, v := range order {
		ruler[v-'a'] = i
	}
	alienCmp := func(s1, s2 string) bool {
		i1 := 0
		i2 := 0
		for i1 < len(s1) && i2 < len(s2) {
			if ruler[s1[i1]-'a'] > ruler[s2[i2]-'a'] {
				return false
			} else if ruler[s1[i1]-'a'] < ruler[s2[i2]-'a'] {
				return true
			}
			i1++
			i2++
		}
		if i1 < len(s1) {
			return false
		}
		return true
	}
	i := 0
	for i < len(words)-1 {
		if !alienCmp(words[i], words[i+1]) {
			return false
		}
		i++
	}
	return true
}
