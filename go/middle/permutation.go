package main

func permutation(S string) []string {
	s2b := []byte(S)
	var rs []string
	var dfs func(cur int)
	dfs = func(cur int) {
		if cur == len(s2b) {
			rs = append(rs, string(s2b))
			return
		}
		for i := cur; i < len(s2b); i++ {
			s2b[cur], s2b[i] = s2b[i], s2b[cur]
			dfs(cur + 1)
			s2b[cur], s2b[i] = s2b[i], s2b[cur]
		}
	}
	dfs(0)
	return rs
}
