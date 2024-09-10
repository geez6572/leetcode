package main

import "fmt"

func wardrobeFinishing(m int, n int, cnt int) int {
	if m == 1 {
		return min(cnt+1, n)
	}
	if n == 1 {
		return min(cnt+1, m)
	}
	digit := func(x int) (rs int) {
		rs = 0
		for x > 0 {
			rs += x % 10
			x = x / 10
		}
		return
	}
	visited := make([][]bool, m)
	for i := range visited {
		visited[i] = make([]bool, n)
	}
	rs := 0
	var dfs func(x, y int)
	dfs = func(x, y int) {
		if x == m || y == n || visited[x][y] || (digit(x)+digit(y) > cnt) {
			return
		}
		rs++
		visited[x][y] = true
		dfs(x+1, y)
		dfs(x, y+1)
	}
	return rs
}

func main() {
	rs := wardrobeFinishing(1, 64, 11)
	fmt.Println(rs)
}
