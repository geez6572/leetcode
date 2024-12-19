package main

func stableMountains(height []int, threshold int) []int {
	rs := make([]int, 0)
	for i := 1; i < len(height); i++ {
		if height[i-1] > threshold {
			rs = append(rs, i)
		}
	}
	return rs
}
