package main

func bestTiming(prices []int) int {
	pre := prices[0]
	rs := 0
	for i := 0; i < len(prices)-1; i++ {
		if prices[i] < pre {
			pre = prices[i]
			continue
		}
		rs = max(rs, prices[i]-pre)
	}
	return rs
}
