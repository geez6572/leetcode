package main

func oddCells(m int, n int, indices [][]int) int {
	var rs [][]int = make([][]int, m)
	for i := range rs {
		rs[i] = make([]int, n)
	}

	for _, arr := range indices {
		for i := 0; i < n; i++ {
			rs[arr[0]][i]++
		}
		for i := 0; i < m; i++ {
			rs[i][arr[1]]++
		}
	}
	count := 0
	for _, arr := range rs {
		for _, v := range arr {
			if v%2 == 1 {
				count++
			}
		}
	}
	return count
}
