package main

func generateParenthesis(n int) []string {
	cur := []byte{}
	rs := []string{}
	var dfs func(left, right int)
	dfs = func(left, right int) {
		if left+right == 2*n {
			rs = append(rs, string(cur))
			return
		}
		if left < n && left > right {
			cur = append(cur, '(')
			dfs(left+1, right)
			cur = cur[:len(cur)-1]
			cur = append(cur, ')')
			dfs(left, right+1)
			cur = cur[:len(cur)-1]
		} else if left == right {
			cur = append(cur, '(')
			dfs(left+1, right)
			cur = cur[:len(cur)-1]
		} else {
			cur = append(cur, ')')
			dfs(left, right+1)
			cur = cur[:len(cur)-1]
		}
	}
	dfs(0, 0)
	return rs
}
