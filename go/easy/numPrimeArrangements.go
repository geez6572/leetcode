package main

import "math"

func isPrime(num int) bool {
	border := int(math.Sqrt(float64(num)))
	for i := 2; i <= border; i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func numPrimeArrangements(n int) int {
	s := make([]int, n+1)
	for i := 2; i <= n; i++ {
		if isPrime(i) {
			s[i] = s[i-1] + 1
		} else {
			s[i] = s[i-1]
		}
	}
	rs := 1
	for i := 1; i <= s[n]; i++ {
		rs = (rs * i) % (1000000007)
	}
	for i := 1; i <= n-s[n]; i++ {
		rs = (rs * i) % (1000000007)
	}
	return rs
}
