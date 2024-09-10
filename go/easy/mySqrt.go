package main

func mySqrt(x int) int {
	left := 0
	right := x
	for left < right {
		mid := left + (right-left)/2
		if (x/mid > mid && (x/(mid+1) < mid)) || x/mid == mid {
			return mid
		} else if x/mid > mid {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return left
}
