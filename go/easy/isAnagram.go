package main

func isAnagram(s string, t string) bool {
	sc := [26]int{}
	tc := [26]int{}
	for i := range s {
		sc[s[i]-'a']++
	}
	for i := range t {
		tc[t[i]-'a']++
	}
	for i := range 26 {
		if sc[i] != tc[i] {
			return false
		}
	}
	return true
}
