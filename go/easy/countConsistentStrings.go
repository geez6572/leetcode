package main

import "fmt"

func countConsistentStrings(allowed string, words []string) int {
	pos := 0
	for i := range allowed {
		pos = pos | (1 << (allowed[i] - 'a'))
	}
	rs := 0
	fmt.Println(pos)
out:
	for i := range words {
		for k := range words[i] {
			if pos&(1<<(words[i][k]-'a')) == 0 {
				continue out
			}
		}
		rs++
	}
	return rs
}

func main() {
	words := []string{"ad", "bd", "aaab", "baa", "badab"}
	countConsistentStrings("ab", words)
}
