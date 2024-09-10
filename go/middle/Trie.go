package main

type Trie struct {
	val    byte
	childs [26]*Trie
	isEnd  bool
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{val: ' '}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	for i := range word {
		if this.childs[word[i]-'a'] == nil {
			this.childs[word[i]-'a'] = &Trie{val: word[i]}
		}
		this = this.childs[word[i]-'a']
		if i == len(word)-1 {
			this.isEnd = true
		}
	}
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	for i := range word {
		if this.childs[word[i]-'a'] == nil {
			return false
		}
		this = this.childs[word[i]-'a']
	}
	return this.isEnd
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	for i := range prefix {
		if this.childs[prefix[i]-'a'] == nil {
			return false
		}
		this = this.childs[prefix[i]-'a']
	}
	return true
}
