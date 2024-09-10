package main

func judgeNoZero(a int) bool {
	for a > 0 {
		if a%10 == 0 {
			return false
		}
		a = a / 10
	}
	return true
}

func getNoZeroIntegers(n int) []int {
	rs := []int{}
	for i := 1; i <= n/2; i++ {
		if judgeNoZero(i) && judgeNoZero(n-i) {
			rs = append(rs, i)
			rs = append(rs, n-i)
			break
		}
	}
	return rs
}
