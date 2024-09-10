package main

func myCompare(a, b []byte) bool {
	for i := range a {
		if a[i] > b[i] {
			return false
		}
	}
	return true
}

func shortestCompletingWord(licensePlate string, words []string) string {
	count1 := [26]byte{}
	for _, v := range licensePlate {
		if v >= 'a' && v <= 'z' {
			count1[v-'a']++
		} else if v >= 'A' && v <= 'Z' {
			count1[v-'A']++
		}
	}

	rs := -1
	for i := range words {
		temp := [26]byte{}
		for _, v := range words[i] {
			if v >= 'a' && v <= 'z' {
				temp[v-'a']++
			} else if v >= 'A' && v <= 'Z' {
				temp[v-'A']++
			}
		}
		if myCompare(count1[:], temp[:]) && (rs == -1 || len(words[i]) < len(words[rs])) {
			rs = i
		}
	}
	return words[rs]
}

func main() {
	licensePlate := "1s3 PSt"
	words := [...]string{"step", "steps", "stripe", "stepple"}

	shortestCompletingWord(licensePlate, words[:])
}
