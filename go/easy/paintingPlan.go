package main

func paintingPlan(n int, k int) int {
	if k == 0 || k == n*n {
		return 1
	}
	curLen := n
	x := k / n
	y := k % n
}
