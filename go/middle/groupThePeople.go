package main

func groupThePeople(groupSizes []int) [][]int {
	m := map[int]int{}
	rs := [][]int{}
	for i := range groupSizes {
		if v, e := m[groupSizes[i]]; e && len(rs[v]) < groupSizes[i] {
			rs[v] = append(rs[v], i)
		} else {
			newArr := []int{i}
			rs = append(rs, newArr)
			m[groupSizes[i]] = len(rs) - 1
		}
	}
	return rs
}
