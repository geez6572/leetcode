package main

func maximalRectangle(matrix []string) int {
	prefix := make([][]int, len(matrix)+1)
	for i := range prefix {
		prefix[i] = make([]int, len(matrix[i])+1)
	}
	for i := 1; i < len(prefix); i++ {
		for k := 1; k < len(prefix[i]); k++ {
			prefix[i][k] = prefix[i-1][k] + prefix[i][k-1] - prefix[i-1][k-1] + int(matrix[i-1][k-1]-'0')
		}
	}
}
