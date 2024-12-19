package main

import "fmt"

func closedIsland(grid [][]int) int {
	var dfs func(x, y int) bool
	dir := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	dfs = func(x, y int) bool {
		if x >= len(grid) || x < 0 || y >= len(grid[0]) || y < 0 {
			return false
		}
		if grid[x][y] == 1 {
			return true
		}
		grid[x][y] = 1
		rs := true
		for i := range dir {
			next_x := x + dir[i][0]
			next_y := y + dir[i][1]
			rs = dfs(next_x, next_y) && rs
		}
		return rs
	}
	cnt := 0
	for i := range grid {
		for k := range grid[i] {
			if grid[i][k] == 1 {
				continue
			}
			if i == 1 && k == 5 {
				fmt.Println("aa")
			}
			if dfs(i, k) {
				cnt++
			}
		}
	}
	return cnt
}

func main() {
	grid := [][]int{{0, 0, 1, 1, 0, 1, 0, 0, 1, 0}, {1, 1, 0, 1, 1, 0, 1, 1, 1, 0}, {1, 0, 1, 1, 1, 0, 0, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 1, 1, 1}, {1, 0, 1, 0, 1, 1, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 1, 0, 1, 0, 1}, {1, 1, 1, 0, 1, 1, 0, 1, 1, 0}}
	fmt.Println(closedIsland(grid))
}
