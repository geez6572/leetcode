package main

func maxAreaOfIsland(grid [][]int) int {
	visited := make([][]bool, len(grid))
	for i := range visited {
		visited[i] = make([]bool, len(grid[i]))
	}

	dir := [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	var dfs func(x, y int) int
	dfs = func(x, y int) int {
		if visited[x][y] || grid[x][y] == 0 {
			return 0
		}
		rs := 1
		visited[x][y] = true
		for i := 0; i < 4; i++ {
			newX := x + dir[i][0]
			newY := y + dir[i][1]
			if newX >= 0 && newX < len(grid) && newY >= 0 && newY < len(grid[0]) {
				rs += dfs(newX, newY)
			}
		}
		return rs
	}
	ans := 0
	for i := range grid {
		for k := range grid[i] {
			cur := dfs(i, k)
			ans = max(ans, cur)
		}
	}
	return ans
}
