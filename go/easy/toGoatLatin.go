package main

import (
	"strings"
	"unicode"
)

func isYuan(b byte) bool {
	if b >= 'A' && b <= 'Z' {
		b = 'a' + b - 'A'
	}
	return b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u'
}

func toGoatLatin(sentence string) string {
	var rs string
	splits := strings.Split(sentence, " ")
	for i := range splits {
		if rs != "" {
			rs += " "
		}
		var cur string = splits[i]
		if !isYuan(cur[0]) {
			cur = cur[1:] + cur[0:1]
		}
		cur = cur + "ma"
		for k := 0; k <= i; k++ {
			cur += "a"
		}
		rs += cur
	}
	return rs
}
