package main

func tictactoe(moves [][]int) string {
	chessBoard := [3][3]byte{}
	flagX := true
	for i := range moves {
		if flagX {
			chessBoard[moves[i][0]][moves[i][1]] = 'X'
		} else {
			chessBoard[moves[i][0]][moves[i][1]] = 'O'
		}
		flagX = !flagX
	}
	for i := 0; i < 3; i++ {
		row := 0
		col := 0
		for k := 0; k < 3; k++ {
			if chessBoard[i][k] == 'X' {
				row++
			} else if chessBoard[i][k] == 'O' {
				row--
			}
			if chessBoard[k][i] == 'X' {
				col++
			} else if chessBoard[k][i] == 'O' {
				col--
			}
		}
		if row == 3 || col == 3 {
			return "A"
		} else if row == -3 || col == -3 {
			return "B"
		}
	}
	tile := 0
	rtile := 0
	for i := 0; i < 3; i++ {
		if chessBoard[i][i] == 'X' {
			tile++
		} else if chessBoard[i][i] == 'O' {
			tile--
		}
		if chessBoard[i][2-i] == 'X' {
			rtile++
		} else if chessBoard[i][2-i] == 'O' {
			rtile--
		}
	}
	if tile == 3 || rtile == 3 {
		return "A"
	} else if tile == -3 || rtile == -3 {
		return "B"
	}
	if len(moves) == 9 {
		return "Draw"
	} else {
		return "Pending"
	}
}
