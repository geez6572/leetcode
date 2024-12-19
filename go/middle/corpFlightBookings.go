package main

func corpFlightBookings(bookings [][]int, n int) []int {
	ans := make([]int, n)
	for i := range bookings {
		for k := bookings[i][0]; k <= bookings[i][1]; k++ {
			ans[k] += bookings[i][2]
		}
	}
	return ans
}

func corpFlightBookings_diff(bookings [][]int, n int) []int {
	diff := make([]int, n+1)
	for _, v := range bookings {
		diff[v[0]-1] += v[2]
		diff[v[1]] -= v[2]
	}
	rs := make([]int, n)
	rs[0] = diff[0]
	for i := 1; i < len(rs); i++ {
		rs[i] = diff[i] + rs[i-1]
	}
	return rs
}
