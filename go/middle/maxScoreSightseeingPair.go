package main

func maxScoreSightseeingPair(values []int) int {
	left := 0
	right := 1
	rs := 0
	for right < len(values) {
		rs = max(rs, values[left]+left+values[right]-right)
		if values[right]+right >= values[left]+left {
			left = right
		}
		right++
	}
	return rs
}
