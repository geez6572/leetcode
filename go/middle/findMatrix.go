package main

import "fmt"

func findMatrix(nums []int) [][]int {
	m := make(map[int]int)
	for i := range nums {
		m[nums[i]]++
	}
	rs := make([][]int, 0)
	for len(m) > 0 {
		cur := make([]int, 0)
		for k, v := range m {
			cur = append(cur, k)
			if v == 1 {
				delete(m, k)
			} else {
				m[k]--
			}
		}
		rs = append(rs, cur)
	}
	return rs
}

func main() {
	m := make(map[int]int)
	m[1] = 10
	m[2] = 10
	for k, v := range m {
		m[k]++
		v++
	}
	for k, v := range m {
		fmt.Println(k, ":", v)
	}
}
