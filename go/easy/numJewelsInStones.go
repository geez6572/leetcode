package main

func numJewelsInStones(jewels string, stones string) int {
	mappings := map[rune]int{}
	for _, v := range jewels {
		if _, exist := mappings[v]; !exist {
			mappings[v] = 1
		}
	}

	rs := 0
	for _, v := range stones {
		if _, exist := mappings[v]; exist {
			rs++
		}
	}
	return rs
}
