package main

func isValidSudoku(board [][]byte) bool {
	// check every row and row
	for i := 0; i < 9; i++ {
		rowM := [10]int{}
		colM := [10]int{}
		for k := 0; k < 9; k++ {
			if board[i][k] != '.' {
				rowM[board[i][k]-'0']++
				if rowM[board[i][k]-'0'] > 1 {
					return false
				}
			}
			if board[i][k] != '.' {
				colM[board[k][i]-'0']++
				if colM[board[k][i]-'0'] > 1 {
					return false
				}
			}
		}
	}

	// check every 3x3 grid
	for i := 0; i < 9; i++ {
		startX := (i / 3) * 3
		startY := (i % 3) * 3
		gridM := [10]int{}
		for row := startX; row < startX+3; row++ {
			for col := startY; col < startY+3; col++ {
				if gridM[board[row][col]] != '.' {
					gridM[board[row][col]-'0']++
					if gridM[board[row][col]-'0'] > 1 {
						return false
					}
				}
			}
		}
	}
	return true
}
