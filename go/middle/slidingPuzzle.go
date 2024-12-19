package main

func slidingPuzzle(board [][]int) int {
	type node struct {
		b   [][]int
		pre int
	}
	ans := [][]int{{1, 2, 3}, {4, 5, 0}}
	queue := make([]node, 0)
	queue = append(queue, node{b: board, pre: 0})
}
