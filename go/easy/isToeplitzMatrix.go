package main

func isToeplitzMatrix(matrix [][]int) bool {
	for i := 1; i < len(matrix); i++ {
		for k := 1; k < len(matrix[0]); k++ {
			if matrix[i][k] != matrix[i-1][k-1] {
				return false
			}
		}
	}
	return true
}
