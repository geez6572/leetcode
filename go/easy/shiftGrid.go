package main

import "fmt"

func shiftGrid(grid [][]int, k int) [][]int {
	row := len(grid)
	col := len(grid[0])
	k = k % (row * col)
	rs := make([][]int, row)
	for i := range rs {
		rs[i] = make([]int, col)
	}
	for i := range grid {
		for j, v := range grid[i] {
			next_col := j + (k % col)
			next_row := i + (k / col)
			if next_col >= col {
				next_col = next_col % col
				next_row++
			}
			if next_row >= row {
				next_row = next_row % row
			}
			rs[next_row][next_col] = v
		}
	}
	return rs[:]
}

func main() {
	grid := [...][]int{{1}, {2}, {3}, {4}, {7}, {6}, {5}}
	rs := shiftGrid(grid[:], 23)
	fmt.Println(rs)
}
