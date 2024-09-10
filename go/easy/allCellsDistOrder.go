package main

import "fmt"

func allCellsDistOrder(rows int, cols int, rCenter int, cCenter int) [][]int {
	visited := make([][]bool, rows)
	next := [4][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	for i := range visited {
		visited[i] = make([]bool, cols)
	}
	queue := [][]int{}
	cur := []int{rCenter, cCenter}
	i := 0
	queue = append(queue, cur)
	visited[rCenter][cCenter] = true
	for i < len(queue) {
		cur = queue[i]
		i++
		for k := range next {
			next_row := cur[0] + next[k][0]
			next_col := cur[1] + next[k][1]
			if next_col >= 0 && next_col < cols && next_row >= 0 && next_row < rows && !visited[next_row][next_col] {
				temp := []int{next_row, next_col}
				queue = append(queue, temp)
				visited[next_row][next_col] = true
			}
		}
	}
	return queue
}

func main() {
	rs := allCellsDistOrder(2, 3, 1, 2)
	for i := range rs {
		for k := range rs[0] {
			fmt.Print(rs[i][k], " ")
		}
		fmt.Println()
	}
}
