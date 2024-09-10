package main

func gameOfLife(board [][]int) {
	for i := 1; i < len(board); i++ {
		board[i][0] += board[i-1][0]
	}
	for i := 1; i < len(board[0]); i++ {
		board[0][i] += board[0][i-1]
	}
	for i := 1; i < len(board); i++ {
		for k := 1; k < len(board[i]); k++ {
			board[i][k] = board[i-1][k] + board[i][k-1] - board[i-1][k-1]
		}
	}
}
