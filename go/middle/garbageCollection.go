package main

func garbageCollection(garbage []string, travel []int) int {
	last := [3]int{}
	rs := 0
	prefix := make([]int, len(garbage))
	for i := 1; i < len(prefix); i++ {
		prefix[i] = prefix[i-1] + travel[i-1]
	}
	for i := range garbage {
		rs += len(garbage[i])
		for k := range garbage[i] {
			if garbage[i][k] == 'M' {
				last[0] = i
			} else if garbage[i][k] == 'P' {
				last[1] = i
			} else {
				last[2] = i
			}
		}
	}
	for i := range last {
		rs += prefix[last[i]]
	}
	return rs
}
