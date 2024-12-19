package main

func shipWithinDays(weights []int, days int) int {
	sum := 0
	for i := range weights {
		sum += weights[i]
	}
	avg := sum / days
	if sum%days != 0 {
		avg++
	}
	rs := sum
	for avg <= sum {
		mid := avg + (sum-avg)/2
		index := 0
		cur := 0
		cnt := 0
		for index < len(weights) {
			if weights[index] > mid {
				break
			}
			if cur+weights[index] <= mid {
				if cur == 0 {
					cnt++
				}
				cur += weights[index]
				index++
			} else {
				cur = 0
			}
		}
		if cnt <= days {
			rs = min(rs, mid)
			sum = mid - 1
		} else {
			avg = mid + 1
		}
	}
	return rs
}
