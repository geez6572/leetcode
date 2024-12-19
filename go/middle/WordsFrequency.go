package main

type WordsFrequency struct {
	tire  [26]*WordsFrequency
	count int
}

func Constructor(book []string) WordsFrequency {
	var wf WordsFrequency
	for i := range book {
		cur := &wf
		for k := 0; k < len(book[i]); k++ {
			if cur.tire[book[i][k]-'a'] == nil {
				cur.tire[book[i][k]-'a'] = new(WordsFrequency)
			}
			cur = cur.tire[book[i][k]-'a']
			if k == len(book[i])-1 {
				cur.count++
			}
		}
	}
	return wf
}

func (this *WordsFrequency) Get(word string) int {
	for i := 0; i < len(word); i++ {
		if this.tire[word[i]-'a'] == nil {
			return 0
		}
		this = this.tire[word[i]-'a']
	}
	return this.count
}
