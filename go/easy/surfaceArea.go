package main

var direction = [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}

func surfaceArea(grid [][]int) int {
	rs := 0
	m := len(grid)
	n := len(grid[0])
	for i := range grid {
		for k := range grid[0] {
			if grid[i][k] > 0 {
				rs += 2
				for _, v := range direction {
					adj_i := i + v[0]
					adj_k := k + v[1]
					if adj_i < 0 || adj_i >= m || adj_k < 0 || adj_k >= n {
						rs += grid[i][k]
					} else {
						rs += max(0, grid[i][k]-grid[adj_i][adj_k])
					}
				}
			}
		}
	}
	return rs
}
