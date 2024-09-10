package main

func distanceBetweenBusStops(distance []int, start int, destination int) int {
	rs1 := 0
	l := len(distance)
	for i := start; i != destination; i = (i + 1) % l {
		rs1 = rs1 + distance[i]
	}
	rs2 := 0
	for i := destination; i != start; i = (i + 1) % l {
		rs2 = rs2 + distance[i]
	}
	return min(rs1, rs2)
}
