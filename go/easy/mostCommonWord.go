package main

import (
	"fmt"
	"strings"
)

func isLetter(c byte) bool {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
}

func mostCommonWord(paragraph string, banned []string) string {
	left := 0
	right := 0
	l := len(paragraph)
	mappings := make(map[string]int)
	for i := range banned {
		mappings[strings.ToLower(banned[i])] = -1
	}
	for right < l {
		for left < l && !isLetter(paragraph[left]) {
			left++
		}
		right = left
		for right < l && isLetter(paragraph[right]) {
			right++
		}
		cur := strings.ToLower(paragraph[left:right])
		if _, exist := mappings[cur]; !exist {
			mappings[cur] = 1
		} else if exist && mappings[cur] != -1 {
			mappings[cur]++
		}
		left = right
	}
	m := 0
	var rs string
	for k, v := range mappings {
		if v > m {
			m = v
			rs = k
		}
	}
	return rs
}

func main() {
	str := "Bob hit a ball, the hit BALL flew far after it was hit."
	banned := []string{"hit"}
	fmt.Println(mostCommonWord(str, banned))
}
