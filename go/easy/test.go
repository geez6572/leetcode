package main

import "fmt"

func main() {
	s1 := "aw"
	for i := range s1 {
		fmt.Println(s1[i])
	}
	println("-------------------")
	for _, v := range s1 {
		fmt.Println(v)
	}
}
