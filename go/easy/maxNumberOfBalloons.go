package main

func maxNumberOfBalloons(text string) int {
	m := [26]uint8{}
	for _, c := range text {
		m[c-'a']++
	}
	rs := min(m[0], m[1], m['l'-'a']/2, m['o'-'a']/2, m['n'-'a'])
	return int(rs)
}
