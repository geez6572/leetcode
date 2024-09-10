package main

import "fmt"

func findIntersectionValues(nums1 []int, nums2 []int) []int {
	map1 := map[int]int{}
	map2 := map[int]int{}
	for _, v := range nums1 {
		c, exist := map1[v]
		if exist {
			map1[v] = c + 1
		} else {
			map1[v] = 1
		}
	}
	rs := [2]int{0, 0}
	for _, v := range nums2 {
		if c, exist := map2[v]; exist {
			map2[v] = c + 1
		} else {
			map2[v] = 1
		}
	}
	for _, v := range nums1 {
		if _, exist := map2[v]; exist {
			rs[0]++
		}
	}
	for _, v := range nums2 {
		if _, exist := map1[v]; exist {
			rs[1]++
		}
	}
	return rs[:]
}

func main() {
	nums1 := [...]int{2, 3, 2}
	nums2 := [...]int{1, 2}
	rs := findIntersectionValues(nums1[:], nums2[:])
	for _, v := range rs {
		fmt.Println(v)
	}
}
