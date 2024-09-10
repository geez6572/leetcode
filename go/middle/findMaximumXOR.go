package main

func findMaximumXOR(nums []int) int {
	rs := 0
	for i := 30; i >= 0; i-- {
		set := make(map[int]bool)
		rs = (rs << 1) + 1
		flag := false
		for _, v := range nums {
			set[v>>i] = true
			if _, e := set[rs^(v>>i)]; e {
				flag = true
				break
			}
		}
		if !flag {
			rs--
		}
	}
	return rs
}
