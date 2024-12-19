package main

import "math"

func nthSuperUglyNumber(n int, primes []int) int {
	dp := make([]int, n)
	dp[0] = 1
	indexs := make([]int, len(primes))
	for i := 1; i < n; i++ {
		m := math.MaxInt
		for k := range indexs {
			m = min(dp[indexs[k]]*primes[k], m)
		}
		for k := range indexs {
			if m == dp[indexs[k]]*primes[k] {
				indexs[k]++
			}
		}
		dp[i] = m
	}
	return dp[n-1]
}
