package main

func findOrder(numCourses int, prerequisites [][]int) []int {
	child := make([][]int, numCourses)
	indegree := make([]int, numCourses)
	for i := range prerequisites {
		child[prerequisites[i][1]] = append(child[prerequisites[i][1]], prerequisites[i][0])
		indegree[prerequisites[i][0]]++
	}
	queue := make([]int, 0)
	for i := range indegree {
		if indegree[i] == 0 {
			queue = append(queue, i)
		}
	}
	rs := make([]int, 0)
	for len(queue) > 0 {
		cur := queue[0]
		queue = queue[1:]
		rs = append(rs, cur)
		for i := range child[cur] {
			indegree[child[cur][i]]--
			if indegree[child[cur][i]] == 0 {
				queue = append(queue, child[cur][i])
			}
		}
	}
	return rs
}
