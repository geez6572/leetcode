package main

func setZeroes(matrix [][]int) {
	rowM := make([]bool, len(matrix))
	colM := make([]bool, len(matrix[0]))
	for i := range matrix {
		for k := range matrix[i] {
			if matrix[i][k] == 0 {
				rowM[i] = true
				colM[k] = true
			}
		}
	}
	for i := range matrix {
		for k := range matrix[i] {
			if rowM[i] || colM[k] {
				matrix[i][k] = 0
			}
		}
	}
}
