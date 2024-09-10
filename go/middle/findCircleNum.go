package main

import "math"

type dsu struct {
	set []int
}

func (this *dsu) find(a int) int {
	if this.set[a] == a {
		return a
	}
	this.set[a] = this.find(this.set[a])
	return this.set[a]
}

func (this *dsu) union(a, b int) {
	if this.set[a] == 0 {
		this.set[a] = a
	}
	if this.set[b] == 0 {
		this.set[b] = b
	}
	pa := this.find(a)
	pb := this.find(b)
	this.set[pa] = pb
}

func findCircleNum(isConnected [][]int) int {
	d := dsu{}
	d.set = make([]int, len(isConnected)+1)
	for i := range isConnected {
		if d.set[i+1] == 0 {
			d.set[i+1] = i + 1
		}

		for k := 0; k < i; k++ {
			if isConnected[i][k] == 1 {
				d.union(i+1, k+1)
			}
		}
	}
	rs := -1
	for i := range d.set {
		if d.set[i] == i {
			rs++
		}
	}
	return rs
}

func main() {
	nums := [][]int{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}
	findCircleNum(nums)
}
