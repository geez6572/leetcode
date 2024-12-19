package main

import (
	"math"
	"sync"
)

func minCost(maxTime int, edges [][]int, passingFees []int) int {
	n := len(passingFees)
	matrix := make([][]int, n)
	for i := range matrix {
		matrix[i] = make([]int, n)
	}
	for i := range edges {
		x := edges[i][0]
		y := edges[i][1]
		time := edges[i][2]
		matrix[x][y], matrix[y][x] = time, time
	}
	visited := make([]bool, n)
	rs := math.MaxInt
	var mu sync.Mutex
	var wg sync.WaitGroup
	var dfs func(cur, time, cost int)
	dfs = func(cur, time, cost int) {
		defer wg.Done()
		if visited[cur] || time > maxTime {
			return
		}
		if cur == n-1 {
			mu.Lock()
			rs = min(rs, cost+passingFees[cur])
			mu.Unlock()
			return
		}
		mu.Lock()
		visited[cur] = true
		mu.Unlock()
		for i := range matrix[cur] {
			if matrix[cur][i] != 0 && !visited[i] {
				wg.Add(1)
				go dfs(i, time+matrix[cur][i], cost+passingFees[cur])
			}
		}
		mu.Lock()
		visited[cur] = false
		mu.Unlock()
	}
	wg.Add(1)
	go dfs(0, 0, 0)
	wg.Wait()
	if rs == math.MaxInt {
		return -1
	}
	return rs
}
