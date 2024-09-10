package main

type dsu struct {
	set []int
}

func Construct(size int) dsu {
	var rs dsu = dsu{}
	rs.set = make([]int, size)
	return rs
}

func (this *dsu) find(n int) int {
	if n == this.set[n] {
		return n
	}
	this.set[n] = this.find(this.set[n])
	return this.set[n]
}

func (this *dsu) merge(a, b int) {
	if this.set[a] == 0 {
		this.set[a] = a
	}
	if this.set[b] == 0 {
		this.set[b] = b
	}
	ap := this.find(a)
	bp := this.find(b)
	this.set[bp] = ap
}

func findRedundantConnection(edges [][]int) []int {
	s := Construct(len(edges) + 1)
	for i := range edges {
		a := s.find(edges[i][0])
		b := s.find(edges[i][1])
		if a != 0 && a == b {
			return edges[i]
		}
		s.merge(edges[i][0], edges[i][1])
	}
	return []int{}
}
