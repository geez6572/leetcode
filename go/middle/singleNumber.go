package main

func singleNumber(nums []int) int {
	x := 0
	for _, v := range nums {
		x = x ^ v
	}
	diff := 1
	for x&diff == 0 {
		diff = diff << 1
	}
	a, b := 0, 0
	for _, v := range nums {
		if (v & diff) == 0 {
			a = a ^ v
		} else {
			b = b ^ v
		}
	}
}
