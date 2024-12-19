package main

import "sort"

func leastInterval(tasks []byte, n int) int {
	count := [26]int{}
	for _, v := range tasks {
		count[v-'A']++
	}
	sort.Ints(count[:])
	if n >= 26 {
		rs := n * (count[0] - 1)
		add := 0
		for i := range count {
			if count[i] != count[0] {
				break
			}
			add++
		}
		return rs + add
	}
}
