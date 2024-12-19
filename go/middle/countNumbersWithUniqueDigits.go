package main

func countNumbersWithUniqueDigits(n int) int {
	inNum := [10]bool{}
	rs := 0
	board := 1
	for i := 0; i < n; i++ {
		board *= 10
	}
	var backtrace func(int)
	backtrace = func(cur int) {
		if cur > board {
			return
		}
		rs++
		for i := 0; i < 10; i++ {
			if inNum[i] || (cur == 0 && i == 0) {
				continue
			}
			inNum[i] = true
			backtrace(cur*10 + i)
			inNum[i] = false
		}
	}
	backtrace(0)
	return rs
}

func countNumbersWithUniqueDigits2(n int) int {
	if n == 0 {
		return 1
	}
	rs := 10
	last := 9
	for i := 2; i <= n; i++ {
		cur := last * (10 - i + 1)
		rs += cur
		last = cur
	}
	return rs
}
