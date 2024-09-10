package main

import (
	"fmt"
	"math"
)

func countPrimeSetBits(left int, right int) int {
	rs := 0
	for i := left; i <= right; i++ {
		temp := i
		count := 0
		for temp > 0 {
			if temp&1 == 1 {
				count++
			}
			temp = temp >> 1
		}
		if count == 1 {
			break
		}
		flag := true
		for k := 2; k <= int(math.Sqrt(float64(count))); k++ {
			if count%k == 0 {
				flag = false
				break
			}
		}
		if flag {
			rs++
		}
	}
	return rs
}

func main() {
	fmt.Println(countPrimeSetBits(6, 10))
}
