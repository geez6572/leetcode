package main

import "fmt"

func hasGroupsSizeX(deck []int) bool {
	m := make(map[int]int)
	share := [10001]int{}
	for _, v := range deck {
		m[v]++
	}
	for _, v := range m {
		if v == 1 {
			return false
		}
		for i := 2; i <= v; i++ {
			if v%i == 0 {
				share[i]++
				for v > 0 && v%i == 0 {
					v = v / i
				}
			}
		}
	}
	for _, v := range share {
		if v == len(m) {
			return true
		}
	}
	return false
}

func main() {
	nums := []int{1, 2, 3, 4, 4, 3, 2, 1}
	fmt.Println(hasGroupsSizeX(nums))
}
