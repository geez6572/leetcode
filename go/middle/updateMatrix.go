package main

func updateMatrix(mat [][]int) [][]int {
	queue := make([][2]int, 0)
	rs := make([][]int, len(mat))
	for i := 0; i < len(mat); i++ {
		rs[i] = make([]int, len(mat[i]))
		for k := 0; k < len(mat[i]); k++ {
			rs[i][k] = -1
			if mat[i][k] == 0 {
				rs[i][k] = 0
				queue = append(queue, [2]int{i, k})
			}
		}
	}
	dir := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	for len(queue) > 0 {
		l := len(queue)
		for i := 0; i < l; i++ {
			temp := queue[0]
			queue = queue[1:]
			for k := 0; k < 4; k++ {
				x := temp[0] + dir[k][0]
				y := temp[1] + dir[k][1]
				if x >= 0 && x < len(mat) && y >= 0 && y < len(mat[0]) && rs[x][y] == -1 {
					rs[x][y] = rs[temp[0]][temp[1]] + 1
					queue = append(queue, [2]int{x, y})
				}
			}
		}
	}
	return rs
}
