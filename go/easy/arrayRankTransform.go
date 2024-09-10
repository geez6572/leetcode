package main

import "sort"

func arrayRankTransform(arr []int) []int {
	temp := make([]int, len(arr))
	copy(temp, arr)
	sort.Ints(temp)
	m := make(map[int]int)
	cur := 1
	for i := range temp {
		if _, exist := m[temp[i]]; !exist {
			m[temp[i]] = cur
			cur++
		}
	}
	var rs []int
	for i := range arr {
		rs = append(rs, m[arr[i]])
	}
	return rs
}
