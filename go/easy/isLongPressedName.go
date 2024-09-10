package main

func isLongPressedName(name string, typed string) bool {
	ni := 0
	ti := 0
	for ni < len(name) && ti < len(typed) {
		if name[ni] != typed[ti] {
			return false
		}
		cur := name[ni]
		count1 := 0
		for ni < len(name) && name[ni] == cur {
			count1++
		}
		count2 := 0
		for ti < len(typed) && typed[ti] == cur {
			count2++
		}
		if count1 > count2 {
			return false
		}
	}
	if ni < len(name) || ti < len(typed) {
		return false
	}
	return true
}
