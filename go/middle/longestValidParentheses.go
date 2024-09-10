package main

func longestValidParentheses(s string) int {
	dp := make([][]bool, len(s))
	for i := range dp {
		dp[i] = make([]bool, len(s))
	}
	rs := 0
	for i := 0; i < len(s); i++ {
		for k := i; k >= 0; k-- {
			if k == i {
				continue
			}
			if s[k] == '(' && s[i] == ')' && (k+1 > i-1 || dp[k+1][i-1]) {
				dp[k][i] = true
			}
		}
	}
}
