package main

func maxSatisfied(customers []int, grumpy []int, minutes int) int {
	rs := 0
	for i := range customers {
		if grumpy[i] == 0 {
			rs += customers[i]
		}
	}
	left := 0
	right := 0
	for right < minutes && right < len(customers) {
		if grumpy[right] == 1 {
			rs += customers[right]
		}
		right++
	}
	cur := rs
	for right < len(customers) {
		if grumpy[right] == 1 {
			cur += customers[right]
		}
		if grumpy[left] == 1 {
			cur -= customers[left]
		}
		left++
		right++
		rs = max(rs, cur)
	}
	return rs
}
