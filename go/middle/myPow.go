package main

func myPow(x float64, n int) float64 {
	if n == 0 {
		return 1
	}
	if n < 0 {
		x = 1 / x
		n = -n
	}
	var rs float64 = 1
	var cur float64 = 1
	i := 0
	count := 0
	for i < n {
		if i == 0 {
			cur = cur * x
			i++
		} else if i*2 <= n {
			cur = cur * cur
			i = i * 2
		}
		if (1<<count)&n == 1 {
			rs *= cur
		}
		count++
	}
	return rs
}
