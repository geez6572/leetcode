package main

import "sort"

func minimumLengthEncoding(words []string) int {
	m := make(map[string]bool)
	sort.Slice(words, func(i, j int) bool {
		return len(words[i]) > len(words[j])
	})
	rs := 0
	for i := 0; i < len(words); i++ {
		for k := range words[i] {
			if _, e := m[words[i][k:]]; e {
				continue
			}
			m[words[i][k:]] = true
			if k == 0 {
				rs += len(words[i])
			}
		}
	}
	return rs
}

type dic struct {
	childs [26]*dic
}

func (this *dic) insert(s string) int {
	rs := 0
	flag := false
	for i := len(s) - 1; i >= 0; i-- {
		if this.childs[s[i]-'a'] == nil {
			this.childs[s[i]-'a'] = new(dic)
			flag = true
		}
		rs++
		this = this.childs[s[i]-'a']
	}
	if flag {
		return rs + 1
	}
	return 0
}

func minimumLengthEncoding2(words []string) int {
	sort.Slice(words, func(i, j int) bool {
		return len(words[i]) > len(words[j])
	})
	rs := 0
	var d dic
	for i := range words {
		rs += d.insert(words[i])
	}
	return rs
}
