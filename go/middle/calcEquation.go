package main

type pair struct {
	val     float64
	variety string
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	m := make(map[string][]int)
	rm := make(map[string][]int)
	for i := range equations {
		if v, e := m[equations[i][0]]; e {
		}
	}
}
