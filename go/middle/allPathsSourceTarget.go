package main

func allPathsSourceTarget(graph [][]int) [][]int {
	visited := make([]bool, len(graph))
	rs := [][]int{}
	path := []int{}
	var dfs func(index int)
	dfs = func(index int) {
		if visited[index] {
			return
		}
		visited[index] = true
		path = append(path, index)
		if index == len(graph)-1 {
			rs = append(rs, append([]int{}, path...))
		}
		for i := range graph[index] {
			if !visited[graph[index][i]] {
				dfs(graph[index][i])
			}
		}
		path = path[:len(path)-1]
		visited[index] = false
	}
	dfs(0)
	return rs
}
