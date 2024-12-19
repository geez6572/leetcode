package main

func carPooling(trips [][]int, capacity int) bool {
	diff := make([]int, 1010)
	for i := range trips {
		increase := trips[i][0]
		left := trips[i][1]
		right := trips[i][2]
		diff[left] += increase
		diff[right+1] -= increase
	}
	for i := 1; i < len(diff); i++ {
		diff[i] = diff[i] + diff[i-1]
		if diff[i] > capacity {
			return false
		}
	}
	return true
}
