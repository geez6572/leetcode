package main

import "strings"

type Trie struct {
	childs [26]*Trie
	isEnd  bool
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	for i := range word {
		if this.isEnd {
			break
		}
		if this.childs[word[i]-'a'] == nil {
			this.childs[word[i]-'a'] = &Trie{}
		}
		this = this.childs[word[i]-'a']
		if i == len(word)-1 {
			this.isEnd = true
		}
	}
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) string {
	for i := range word {
		if this.childs[word[i]-'a'] == nil {
			return word
		}
		this = this.childs[word[i]-'a']
		if this.isEnd {
			return word[:i+1]
		}
	}
	return word
}

func replaceWords(dictionary []string, sentence string) string {
	split := strings.Split(sentence, " ")
	m := Constructor()
	for i := range dictionary {
		m.Insert(dictionary[i])
	}
	var rs string
	for i := range split {
		rs += m.Search(split[i])
	}
	if len(rs) > 0 {
		rs = rs[:len(rs)-1]
	}
	return rs
}

func main() {
	dictionary := []string{"cat", "bat", "rat"}
	sentence := "the cattle was rattled by the battery"
	replaceWords(dictionary, sentence)
}
