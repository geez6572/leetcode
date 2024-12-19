package main

func minFallingPathSum(matrix [][]int) int {
	for i := 1; i < len(matrix); i++ {
		for k := 0; k < len(matrix[i]); k++ {
			m := matrix[i-1][k]
			if k-1 >= 0 {
				m = min(matrix[i-1][k-1], m)
			}
			if k+1 < len(matrix[i]) {
				m = min(matrix[i-1][k+1], m)
			}
			matrix[i][k] = m + matrix[i][k]
		}
	}
	rs := matrix[len(matrix)-1][0]
	for _, v := range matrix[len(matrix)-1] {
		rs = min(rs, v)
	}
	return rs
}
