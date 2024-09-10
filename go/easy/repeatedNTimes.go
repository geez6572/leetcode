package main

func repeatedNTimes(nums []int) int {
	m := make(map[int]int)
	for _, v := range nums {
		m[v]++
	}

	for k, v := range m {
		if v == len(nums)/2 {
			return k
		}
	}
	return -1
}
