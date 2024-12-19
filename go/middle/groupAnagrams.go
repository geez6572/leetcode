package main

import "sort"

func groupAnagrams(strs []string) [][]string {
	m := make(map[string]int)
	rs := make([][]string, 0)
	for i := range strs {
		toByte := []byte(strs[i])
		sort.Slice(toByte, func(i, j int) bool {
			return toByte[i] < toByte[j]
		})
		toStr := string(toByte)
		if index, ok := m[toStr]; !ok {
			rs = append(rs, []string{strs[i]})
			m[toStr] = len(rs) - 1
		} else {
			rs[index] = append(rs[index], strs[i])
		}
	}
	return rs
}
