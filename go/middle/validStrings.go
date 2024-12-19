package main

func validStrings(n int) []string {
	rs := make([]string, 0)
	var recur func(cur string)
	recur = func(cur string) {
		if len(cur) == n {
			rs = append(rs, cur)
			return
		}
		if len(cur) == 0 || cur[len(cur)-1] == '1' {
			recur(cur + "0")
			recur(cur + "1")
		} else {
			recur(cur + "1")
		}
	}
	return rs
}
