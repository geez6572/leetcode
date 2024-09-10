package main

import "fmt"

func findKthNumber(k int) int {
	if k < 10 {
		return k
	}
	k--
	limit := 0
	limitNum := 0
	increase := 1
	cur := 1
	for limit+increase*9*cur < k {
		limitNum += increase * 9
		limit += increase * 9 * cur
		increase = increase * 10
		cur++
	}
	fmt.Println(cur, " ", limit, " ", limitNum)
	target := limitNum + (k-limit)/cur
	pos := cur
	if (k-limit)%cur != 0 {
		pos = (k - limit) % cur
		target++
	}
	fmt.Println(target, " ", pos)
	for i := 0; i < cur-pos; i++ {
		target = target / 10
	}
	return target % 10
}

func main() {
	findKthNumber(12)
}
