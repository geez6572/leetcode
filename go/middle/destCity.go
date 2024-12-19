package main

func destCity(paths [][]string) string {
	m := make(map[string]int)
	for i := range paths {
		m[paths[i][0]]++
	}
	for i := range paths {
		if _, e := m[paths[i][1]]; !e {
			return paths[i][1]
		}
	}
	return ""
}
