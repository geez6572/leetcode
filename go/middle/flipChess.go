package main

func flipChess(chessboard []string) int {
	board := make([][]int, len(chessboard))
	for i := range board {
		board[i] = make([]int, len(chessboard[i]))
	}
	check := func(x, y int) {
	}
	for i := range chessboard {
		for k := range chessboard[i] {
			if chessboard[i][k] == 'X' {
				check(i, k)
			}
		}
	}
}
