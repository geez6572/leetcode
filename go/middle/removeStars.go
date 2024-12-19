package main

func removeStars(s string) string {
	stack := make([]byte, 0)
	for i := range s {
		if s[i] == '*' && len(s) > 0 {
			stack = stack[:len(stack)-1]
		} else {
			stack = append(stack, s[i])
		}
	}
	return string(stack)
}
