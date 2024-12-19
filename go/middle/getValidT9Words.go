package main

import "strings"

type tire struct {
	childs [26]*tire
	isEnd  bool
}

func getValidT9Words(num string, words []string) []string {
	root := new(tire)
	for _, s := range words {
		travel := root
		for i := range s {
			if travel.childs[s[i]-'a'] == nil {
				travel.childs[s[i]-'a'] = new(tire)
			}
			travel = travel.childs[s[i]-'a']
			if i == len(s)-1 {
				travel.isEnd = true
			}
		}
	}

	key := []string{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	cur := []rune{}
	rs := make([]string, 0)
	var dfs func(int, *tire)
	dfs = func(i int, t *tire) {
		if i >= len(num) {
			if t.isEnd {
				rs = append(rs, string(cur))
			}
			return
		}
		for _, c := range key[num[i]-'2'] {
			if t.childs[c-'a'] == nil {
				continue
			}
			cur = append(cur, c)
			dfs(i+1, t.childs[c-'a'])
			cur = cur[:len(cur)-1]
		}
	}
	dfs(0, root)
	return rs
}

func getValidT9Words2(num string, words []string) []string {
	c2i := [26]int{2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9}
	rs := make([]string, 0)
	for _, s := range words {
		cur := []byte{}
		for i := range s {
			cur = append(cur, byte(c2i[s[i]-'a']+'0'))
		}
		if string(cur) == num {
			rs = append(rs, string(cur))
		}
	}
	return rs
}
