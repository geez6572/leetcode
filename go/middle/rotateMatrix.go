package main

func rotate(matrix [][]int) {
	n := len(matrix)
	for i := 0; i < n; i++ {
		for k := 0; k < n/2; k++ {
			matrix[i][k], matrix[i][n-1-k] = matrix[i][n-1-k], matrix[i][k]
		}
	}

	for i := 0; i < n; i++ {
		for k := 0; k < n-i-1; k++ {
			matrix[i][k], matrix[n-k-1][n-i-1] = matrix[n-k-1][n-i-1], matrix[i][k]
		}
	}
}
