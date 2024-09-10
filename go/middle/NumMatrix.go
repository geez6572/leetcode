package main

import "fmt"

type NumMatrix struct {
	matrix [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	var rs NumMatrix
	rs.matrix = make([][]int, len(matrix)+1)
	for i := range rs.matrix {
		rs.matrix[i] = make([]int, len(matrix[0])+1)
	}
	for i := 1; i < len(rs.matrix); i++ {
		for k := 1; k < len(rs.matrix[i]); k++ {
			rs.matrix[i][k] = rs.matrix[i-1][k] + rs.matrix[i][k-1] - rs.matrix[i-1][k-1] + matrix[i-1][k-1]
		}
	}
	return rs
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	return this.matrix[row2+1][col2+1] - this.matrix[row2+1][col1] - this.matrix[row1][col2+1] + this.matrix[row1][col1]
}

func main() {
	matrix := [][]int{{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}}
	obj := Constructor(matrix)
	for i := range obj.matrix {
		for k := range obj.matrix[i] {
			fmt.Print(obj.matrix[i][k], " ")
		}
		fmt.Println()
	}
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
