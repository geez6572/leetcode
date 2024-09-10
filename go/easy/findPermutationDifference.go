package main

import "math"

func findPermutationDifference(s string, t string) int {
	m := [26]int{}
	rs := 0
	for i := range s {
		m[s[i]-'a'] = i
	}
	for i := range t {
		rs += int(math.Abs(float64(m[t[i]-'a'] - i)))
	}
	return rs
}
