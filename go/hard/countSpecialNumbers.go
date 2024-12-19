package main

func countSpecialNumbers(n int) int {
	rs := 0
	var recur func(cur int)
	var m [10]bool
	recur = func(cur int) {
		if cur*10 > n {
			return
		}
		for i := 0; i <= 9; i++ {
			temp := cur*10 + i
			if !m[i] && temp <= n && temp != 0 {
				rs++
				m[i] = true
				recur(temp)
				m[i] = false
			}
		}
	}
	recur(0)
	return rs
}
