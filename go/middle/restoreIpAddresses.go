package main

import "strconv"

func restoreIpAddresses(s string) []string {
	rs := []string{}
	var recur func(cur string, index, remain int)
	recur = func(cur string, index, remain int) {
		if index == len(s) && remain == 0 {
			rs = append(rs, cur[:len(cur)-1])
			return
		}
		if len(s)-index > remain*3 || len(s)-index < remain {
			return
		}
		n := 0
		for i := index; i < len(s); i++ {
			n = n*10 + int(s[i]-'0')
			if n == 0 {
				recur(cur+strconv.Itoa(n)+".", i+1, remain-1)
				break
			} else if n > 255 {
				break
			} else {
				recur(cur+strconv.Itoa(n)+".", i+1, remain-1)
			}
		}
	}
	recur("", 0, 4)
	return rs
}
