package main

type MapSum struct {
	next [26]*MapSum
	m    map[string]int
	val  int
}

/** Initialize your data structure here. */
func Constructor() MapSum {
	var rs MapSum
	rs.m = make(map[string]int)
	return rs
}

func (this *MapSum) Insert(key string, val int) {
	if v, e := this.m[key]; e {
		this.m[key] = val
		val = val - v
	}
	for i := range key {
		if this.next[key[i]-'a'] == nil {
			this.next[key[i]-'a'] = new(MapSum)
		}
		this.next[key[i]-'a'].val += val
		this = this.next[key[i]-'a']
	}
}

func (this *MapSum) Sum(prefix string) int {
	for i := 0; i < len(prefix) && this != nil; i++ {
		this = this.next[prefix[i]-'a']
	}
	if this == nil {
		return 0
	}
	return this.val
}
