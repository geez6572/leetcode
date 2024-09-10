package main

func leastMinutes(n int) int {
	cur := 1
	rs := 0
	for cur < n {
		cur = cur * 2
		rs++
	}
	return rs + 1
}
