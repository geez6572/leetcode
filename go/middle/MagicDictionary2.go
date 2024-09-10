package main

type MagicDictionary struct {
	childs [26]*MagicDictionary
	isEnd  bool
}

func Constructor() MagicDictionary {
	return MagicDictionary{}
}

func (this *MagicDictionary) BuildDict(dictionary []string) {
	for i := range dictionary {
		temp := this
		for k := range dictionary[i] {
			if temp.childs[dictionary[i][k]-'a'] == nil {
				temp.childs[dictionary[i][k]-'a'] = new(MagicDictionary)
			}
			temp = temp.childs[dictionary[i][k]-'a']
		}
		temp.isEnd = true
	}
}

func (this *MagicDictionary) Search(searchWord string) bool {
	var dfs func(*MagicDictionary, int, bool) bool
	dfs = func(cur *MagicDictionary, start int, hasChance bool) bool {
		if start == len(searchWord) {
			if hasChance == false && cur.isEnd {
				return true
			}
			return false
		}
		rs := false
		for i := range cur.childs {
			if cur.childs[i] == nil {
				continue
			}
			if i == int(searchWord[start]-'a') {
				rs = dfs(cur.childs[i], start+1, hasChance)
			} else if hasChance {
				rs = dfs(cur.childs[i], start+1, false)
			}
			if rs {
				return rs
			}
		}
		return rs
	}
	return dfs(this, 0, true)
}
