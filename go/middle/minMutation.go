package main

func minMutation(startGene string, endGene string, bank []string) int {
	m := make(map[string]bool)
	for i := range bank {
		m[bank[i]] = true
	}
	if _, e := m[endGene]; !e {
		return -1
	}
	queue := []string{startGene}
	rs := 0
	for len(queue) > 0 {
	}
}
