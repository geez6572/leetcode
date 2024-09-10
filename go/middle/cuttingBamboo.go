package main

func cuttingBamboo(bamboo_len int) int {
	if bamboo_len <= 3 {
		return bamboo_len - 1
	}
	rs := 1
	for bamboo_len > 0 {
		if bamboo_len > 3 && bamboo_len != 4 {
			rs *= 3
			bamboo_len -= 3
		} else {
			rs *= bamboo_len
			break
		}
	}
	return rs
}

func cuttingBamboo_dp(bamboo_len int) int {
	dp := make([]int, bamboo_len+1)
	dp[2] = 1
	for i := 3; i <= bamboo_len; i++ {
		for k := 1; k < i; k++ {
			dp[i] = max(dp[i], max(k*dp[i-k], k*(i-k)))
		}
	}
	return dp[bamboo_len]
}
