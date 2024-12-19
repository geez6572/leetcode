package main

import "math"

func myAtoi(str string) int {
	index := 0
	for index < len(str) && str[index] == ' ' {
		index++
	}
	symbol := false
	if str[index] == '-' {
		symbol = true
		index++
	} else if str[index] == '+' {
		index++
	}
	rs := 0
	for index < len(str) && str[index] <= '9' && str[index] >= '0' {
		rs = rs*10 + int(str[index]-'0')
		index++
		if symbol && -rs <= math.MinInt32 {
			return math.MinInt32
		}
		if !symbol && rs >= math.MaxInt32 {
			return math.MaxInt32
		}
	}
	if symbol {
		return -rs
	}
	return rs
}
