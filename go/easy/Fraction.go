package main

import "fmt"

func fraction(cont []int) []int {
	l := len(cont)
	var rs [2]int
	rs[0] = cont[l-1]
	rs[1] = 1
	for i := len(cont) - 2; i >= 0; i-- {
		temp := rs[0]
		rs[0] = rs[1]
		rs[1] = temp
		rs[0] = rs[0] + cont[i]*rs[1]
	}
	return rs[:]
}

func fff() (a int, b int) {
	a = 1
	b = 99
	return
}

func main() {
	m := map[int]string{}
	m[1] = "aaa"
	rs, exist := m[1]
	fmt.Println(rs, exist)
}
