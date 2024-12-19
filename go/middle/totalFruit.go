package main

func totalFruit(fruits []int) int {
	m := make(map[int]int)
	index := 0
	for index < len(fruits) && len(m) < 2 {
		m[fruits[index]] = index
		index++
	}

	rs := index
	left := 0
	for index < len(fruits) {
		if _, e := m[fruits[index]]; !e {
			pre := fruits[index-1]
			for k, v := range m {
				if k != pre {
					left = v + 1
					delete(m, k)
					break
				}
			}
		}
		m[fruits[index]] = index
		index++
		rs = max(rs, index-left)
	}
	return rs
}
