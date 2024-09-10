package main

func minimumSubstringsInPartition(s string) int {
	dp := make([]int, len(s)+1)
	for i := range s {
		count := 0
		dp[i+1] = len(s)
		m := make([]int, 26)
		freq := 0
		for k := i; k >= 0; k-- {
			if m[s[k]-'a'] == 0 {
				freq++
			}
			m[s[k]-'a']++
			if m[s[k]-'a'] > count {
				count = m[s[k]-'a']
			}
			if len(m)*count == i-k+1 {
				dp[i+1] = min(dp[i+1], dp[k]+1)
			}
		}
	}
	return dp[len(s)]
}

func main() {
	minimumSubstringsInPartition("bccbaacabc")
}
