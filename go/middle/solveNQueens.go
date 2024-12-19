package main

func solveNQueens(n int) [][]string {
	board := make([][]byte, n)
	for i := range board {
		board[i] = make([]byte, n)
		for k := range board[i] {
			board[i][k] = '.'
		}
	}

	var res [][]string

	var check func(x, y int) bool
	check = func(x, y int) bool {
		for i := 0; i < x; i++ {
			if board[i][y] == 'Q' {
				return false
			}
		}

		for i, k := x, y; i >= 0 && k >= 0; i, k = i-1, k-1 {
			if board[i][k] == 'Q' {
				return false
			}
		}
		for i, k := x, y; i >= 0 && k < n; i, k = i-1, k+1 {
			if board[i][k] == 'Q' {
				return false
			}
		}
		return true
	}

	var recur func(curLevel int)
	recur = func(curLevel int) {
		if curLevel == n {
			var ans []string
			for i := range board {
				ans = append(ans, string(board[i]))
			}
			res = append(res, ans)
			return
		}
		for i := 0; i < n; i++ {
			if !check(curLevel, i) {
				continue
			}
			board[curLevel][i] = 'Q'
			recur(curLevel + 1)
			board[curLevel][i] = '.'
		}
	}
	recur(0)
	return res
}
