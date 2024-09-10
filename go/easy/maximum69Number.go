package main

import "fmt"

func maximum69Number(num int) int {
	stack := []int{}
	for num > 0 {
		stack = append(stack, num%10)
		num = num / 10
	}
	cur := len(stack) - 1
	flag := false
	rs := 0
	for cur >= 0 {
		if !flag && stack[cur] == 6 {
			rs = rs*10 + 9
			flag = true
		} else {
			rs = rs*10 + stack[cur]
		}
		cur--
	}
	return rs
}

func main() {
	rs := maximum69Number(9669)
	fmt.Println(rs)
}
