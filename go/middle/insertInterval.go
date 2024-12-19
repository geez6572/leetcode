package main

func insert(intervals [][]int, newInterval []int) [][]int {
	rs := make([][]int, 0)
	inserted := false
	i := 0
	for i < len(intervals) {
		cur := intervals[i]
		i++
		if !inserted {
			if newInterval[0] < cur[0] {
				cur = newInterval
				inserted = true
				i--
			}
		}
		if len(rs) > 0 && rs[len(rs)-1][1] >= cur[0] {
			rs[len(rs)-1][1] = max(rs[len(rs)-1][1], cur[1])
		} else {
			rs = append(rs, append([]int{}, cur...))
		}
	}

	if !inserted {
		if len(rs) > 0 && rs[len(rs)-1][1] >= newInterval[0] {
			rs[len(rs)-1][1] = max(rs[len(rs)-1][1], newInterval[1])
		} else {
			rs = append(rs, append([]int{}, newInterval...))
		}
	}
	return rs
}
