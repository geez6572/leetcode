package main

func numEquivDominoPairs(dominoes [][]int) int {
	grid := [10][10]int{}
	for i := range dominoes {
		if dominoes[i][0] > dominoes[i][1] {
			grid[dominoes[i][0]][dominoes[i][1]]++
		} else {
			grid[dominoes[i][1]][dominoes[i][0]]++
		}
	}
	rs := 0
	for i := 1; i < 10; i++ {
		for k := 1; k <= i; k++ {
			rs += (grid[i][k] * (grid[i][k] - 1) / 2)
		}
	}
	return rs
}
