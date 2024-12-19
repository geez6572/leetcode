package main

func maximumWealth(accounts [][]int) int {
	rs := 0
	for i := range accounts {
		cur := 0
		for k := range accounts[i] {
			cur += accounts[i][k]
		}
		rs = max(rs, cur)
	}
	return rs
}
