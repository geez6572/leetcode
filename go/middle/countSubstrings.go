package main

func countSubstrings(s string) int {
	if len(s) <= 1 {
		return len(s)
	}
	dp := make([][]bool, len(s))
	for i := range dp {
		dp[i] = make([]bool, i+1)
	}
	rs := 1
	dp[0][0] = true
	for i := 1; i < len(s); i++ {
		for k := i; k >= 0; k-- {
			if s[i] == s[k] && (k+1 >= i-1 || dp[i-1][k+1]) {
				dp[i][k] = true
				rs++
			}
		}
	}
	return rs
}

func main() {
	s := "aaa"
	countSubstrings(s)
}
