package main

func binaryGap(n int) int {
	pre := -1
	cur := 0
	rs := 0
	for n > 0 {
		if n&1 == 1 {
			if pre != -1 {
				pre = cur
				rs = max(rs, cur-pre)
			}
			pre = cur
		}
		cur++
		n = n >> 1
	}
	return rs
}
