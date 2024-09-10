package main

func numSimilarGroups(strs []string) int {
	set := make([][]int, len(strs))
	for i := 0; i < len(strs); i++ {
		for k := i + 1; k < len(strs); k++ {
			diff := 0
			for a := range strs[i] {
				if strs[i][a] != strs[k][a] {
					diff++
				}
			}
			if diff <= 2 {
				set[k] = append(set[k], i)
				set[i] = append(set[i], k)
			}
		}
	}
	visited := make([]bool, len(set))
	rs := 0
	var dfs func(int)
	dfs = func(i int) {
		if visited[i] {
			return
		}
		visited[i] = true
		for k := range set[i] {
			dfs(set[i][k])
		}
	}
	for i := range set {
		if visited[i] {
			continue
		}
		dfs(i)
		rs++
	}
	return rs
}

type dsu struct {
	arr []int
}

func (this *dsu) find(x int) int {
	if this.arr[x] == x {
		return x
	}
	this.arr[x] = this.find(this.arr[x])
	return this.arr[x]
}

func (this *dsu) merge(a, b int) {
	if this.arr[a] == -1 {
		this.arr[a] = a
	}
	if this.arr[b] == -1 {
		this.arr[b] = b
	}
	a = this.find(a)
	b = this.find(b)
	this.arr[a] = b
}

func numSimilarGroups2(strs []string) int {
	var d dsu
	d.arr = make([]int, len(strs))
	for i := range d.arr {
		d.arr[i] = -1
	}
	for i := 0; i < len(strs); i++ {
		for k := i + 1; k < len(strs); k++ {
			diff := 0
			for a := range strs[i] {
				if strs[i][a] != strs[k][a] {
					diff++
				}
			}
			if diff <= 2 {
				d.merge(i, k)
			}
		}
	}
	rs := 0
	for i := range d.arr {
		if d.arr[i] == i || d.arr[i] == -1 {
			rs++
		}
	}
	return rs
}
