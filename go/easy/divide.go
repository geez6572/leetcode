package main

func divide(a int, b int) int {
	flag := false
	if a < 0 {
		a = -a
		flag = !flag
	}
	if b < 0 {
		b = -b
		flag = !flag
	}
	rs := 0
	for a > b {
		a = a - b
		rs++
	}

	if flag {
		rs = -rs
	}

	if rs < -2147483648 || rs > 2147483647 {
		return 2147483647
	}
	return rs
}
