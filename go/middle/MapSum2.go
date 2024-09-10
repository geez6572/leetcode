package main

type MapSum struct {
	next [26]*MapSum
	val  int
}

/** Initialize your data structure here. */
func Constructor() MapSum {
	var rs MapSum
	return rs
}

func (this *MapSum) Insert(key string, val int) {
	for i := range key {
		if this.next[key[i]-'a'] == nil {
			this.next[key[i]-'a'] = new(MapSum)
		}
		this = this.next[key[i]-'a']
	}
	this.val = val
}

func (this *MapSum) Sum(prefix string) int {
	for i := 0; i < len(prefix) && this != nil; i++ {
		this = this.next[prefix[i]-'a']
	}
	if this == nil {
		return 0
	}

	var dfs func(node *MapSum) int
	dfs = func(node *MapSum) int {
		if node == nil {
			return 0
		}
		cur := node.val
		for _, v := range node.next {
			cur += dfs(v)
		}
		return cur
	}
	return dfs(this)
}
