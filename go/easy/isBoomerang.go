package main

func isBoomerang(points [][]int) bool {
	for i := 0; i < len(points)-1; i++ {
		if points[i][0] != points[i+1][0] {
			break
		}
		if i == len(points)-2 {
			return false
		}
	}

	for i := 0; i < len(points)-1; i++ {
		if points[i][1] != points[i+1][1] {
			break
		}
		if i == len(points)-2 {
			return false
		}
	}

	for i := 0; i < len(points)-1; i++ {
		if points[i][0]+points[i][1] == points[i+1][0]+points[i+1][1] {
			break
		}
		if i == len(points)-2 {
			return false
		}
	}

	for i := 0; i < len(points)-1; i++ {
		if points[i][0]-points[i][1] == points[i+1][0]-points[i+1][1] {
			break
		}
		if i == len(points)-2 {
			return false
		}
	}
	return true
}
