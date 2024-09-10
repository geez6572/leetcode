package main

import "fmt"

func minEnd(n int, x int) int64 {
	if n == 1 {
		return int64(x)
	}
	temp := x
	i := 0
	arr := make([]int, 0)
	for temp > 0 || i < 63 {
		if temp > 0 {
			if temp&1 == 0 {
				arr = append(arr, i)
			}
			temp = temp >> 1
		} else {
			arr = append(arr, i)
		}
		i++
	}
	add := n - 1
	index := 0
	for add != 0 {
		t := (add & 1) << arr[index]
		x = x | t
		add = add >> 1
		index++
	}
	return int64(x)
}

func main() {
	fmt.Println(minEnd(3, 4))
}
