package main

import "strings"

func findOcurrences(text string, first string, second string) []string {
	rs := []string{}
	split := strings.Split(text, " ")
	for i := 0; i < len(split)-2; i++ {
		if split[i] == first && split[i+1] == second {
			rs = append(rs, split[i+2])
		}
	}
	return rs
}
