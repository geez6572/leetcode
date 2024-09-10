package main

type Employee struct {
	Id           int
	Importance   int
	Subordinates []int
}

func getImportance(employees []*Employee, id int) int {
	idToIndex := make(map[int]int)
	for i := range employees {
		idToIndex[employees[i].Id] = i
	}
	visited := make([]bool, len(employees))
	rs := 0
	var dfs func(cur int)
	dfs = func(cur int) {
		if visited[cur] {
			return
		}
		visited[cur] = true
		rs += employees[cur].Importance
		for _, v := range employees[cur].Subordinates {
			dfs(idToIndex[v])
		}
	}
	dfs(idToIndex[id])
	return rs
}
