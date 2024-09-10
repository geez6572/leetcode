package main

func tribonacci(n int) int {
	if n == 0 {
		return 0
	} else if n <= 2 {
		return 1
	}
	t0 := 0
	t1 := 1
	t2 := 1
	cur := 0
	for i := 3; i <= n; i++ {
		cur = t0 + t1 + t2
		t0 = t1
		t1 = t2
		t2 = cur
	}
	return cur
}
