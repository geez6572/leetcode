package main

import "sort"

func runeReserve(runes []int) int {
	sort.Ints(runes)
	rs := 0
	cur := 0
	for i := 0; i < len(runes); i = i + 1 {
		cur = cur + 1
		if i == len(runes) || runes[i+1]-runes[i] > 1 {
			rs = max(rs, cur)
		}
	}
	return rs
}
