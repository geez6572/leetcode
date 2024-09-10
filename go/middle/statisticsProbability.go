package main

func statisticsProbability(num int) []float64 {
	rs := make([]float64, num*5+1)
	var recur func(count int, cur int, curPro float64)
	recur = func(count int, cur int, curPro float64) {
		if count == num {
			rs[cur] += curPro
			return
		}
		for i := 1; i <= 6; i++ {
			recur(count+1, cur+i, curPro/6)
		}
	}
	recur(0, 0, 1)
	return rs
}

func statisticsProbability_dp(num int) []float64 {
	dp := make([]float64, 6)
	for i := range dp {
		dp[i] = 1.0 / 6.0
	}
	for i := 2; i <= num; i++ {
		temp := make([]float64, i*5+1)
		for k := range dp {
			for j := 0; j < 6; j++ {
				temp[k+j] += dp[k] / 6.0
			}
		}
		dp = make([]float64, len(temp))
		copy(dp, temp)
	}
	return dp
}
