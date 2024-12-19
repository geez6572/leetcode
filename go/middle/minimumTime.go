package main

import "math"

func minimumTime(time []int, totalTrips int) int64 {
	mini := math.MaxInt
	for i := range time {
		mini = min(mini, time[i])
	}
	left := 0
	right := mini * totalTrips
	rs := right
	check := func(val int) bool {
		cur := 0
		for _, v := range time {
			cur += val / v
		}
		if cur >= totalTrips {
			return true
		}
		return false
	}
	for left <= right {
		mid := left + (right-left)>>1
		if check(mid) {
			rs = min(rs, mid)
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return int64(rs)
}
