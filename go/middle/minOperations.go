package main

import "fmt"

func minOperations(boxes string) []int {
	prefix := make([]int, len(boxes)+1)
	rs := make([]int, len(boxes))
	for i := 1; i < len(prefix); i++ {
		prefix[i] = prefix[i-1] + int(boxes[i-1]-'0')
		rs[0] += (i - 1) * int(boxes[i-1]-'0')
	}
	for i := 1; i < len(rs); i++ {
		rs[i] += (prefix[i-1] * 2) + int(boxes[i-1]-'0') - int(boxes[i]-'0') - (prefix[len(prefix)-1]-prefix[i]-int(boxes[i]-'0'))*2 + rs[i-1]
	}
	return rs
}

func main() {
	boxes := "001011"
	rs := minOperations(boxes)
	for i := range rs {
		fmt.Println(rs[i])
	}
}
