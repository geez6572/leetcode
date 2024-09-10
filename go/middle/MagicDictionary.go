package main

type MagicDictionary struct {
	m []string
}

/** Initialize your data structure here. */
func Constructor() MagicDictionary {
	var rs MagicDictionary
	return rs
}

func (this *MagicDictionary) BuildDict(dictionary []string) {
	this.m = make([]string, len(dictionary))
	copy(this.m, dictionary)
}

func (this *MagicDictionary) Search(searchWord string) bool {
	l := len(searchWord)
	for i := range this.m {
		if l != len(this.m[i]) {
			continue
		}
		diff := 0
		for k := range this.m[i] {
			if this.m[i][k] != searchWord[k] {
				diff++
			}
			if diff > 1 {
				return false
			}
		}
		if diff == 1 {
			return true
		}
	}
	return false
}
