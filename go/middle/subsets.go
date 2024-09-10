package main

import "fmt"

func subsets(nums []int) [][]int {
	rs := make([][]int, 0)
	var recur func(index int, cur []int)
	recur = func(index int, cur []int) {
		if index == len(nums) {
			return
		}
		for i := index; i < len(nums); i++ {
			temp := append(cur, nums[i])
			rs = append(rs, temp)
			recur(i+1, temp)
		}
	}
	cur := []int{}
	rs = append(rs, cur)
	recur(0, cur)
	return rs
}

func main() {
	nums := []int{9, 0, 3, 5, 7}
	rs := subsets(nums)
	for i := range rs {
		for k := range rs[i] {
			fmt.Print(rs[i][k], " ")
		}
		fmt.Println()
	}
}
