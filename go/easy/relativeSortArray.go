package main

import "sort"

func relativeSortArray(arr1 []int, arr2 []int) []int {
	m := make(map[int]int)
	for i := range arr2 {
		m[arr2[i]] = i
	}
	sort.Slice(arr1, func(i, j int) bool {
		iv, ie := m[i]
		jv, je := m[j]
		if ie && je {
			return iv < jv
		} else if ie {
			return true
		} else if je {
			return false
		} else {
			return i < j
		}
	})
	return arr1
}

func main() {
	arr1 := []int{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}
	arr2 := []int{2, 1, 4, 3, 9, 6}
	relativeSortArray(arr1, arr2)
}
