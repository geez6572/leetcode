package main

func minFlips(grid [][]int) int {
	row, col := 0, 0
	for i := range grid {
		left := 0
		right := len(grid[i]) - 1
		for left < right {
			if grid[i][left] != grid[i][right] {
				row++
			}
			left++
			right--
		}
	}

	for i := 0; i < len(grid[0]); i++ {
		left := 0
		right := len(grid) - 1
		for left < right {
			if grid[left][i] != grid[right][i] {
				col++
			}
			left++
			right--
		}
	}
	return min(row, col)
}
