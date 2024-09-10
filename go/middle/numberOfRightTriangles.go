package main

func numberOfRightTriangles(grid [][]int) int64 {
	rowOne := make([]int, len(grid))
	colOne := make([]int, len(grid[0]))
	for i := range grid {
		for k := range grid[i] {
			if grid[i][k] == 1 {
				rowOne[i]++
				colOne[k]++
			}
		}
	}
	var rs int64 = 0
	for i := range grid {
		for k := range grid[i] {
			if grid[i][k] == 1 {
				rs += int64(rowOne[i]-1) * int64(colOne[k]-1)
			}
		}
	}
	return rs
}
