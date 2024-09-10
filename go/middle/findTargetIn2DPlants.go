package main

func findTargetIn2DPlants(plants [][]int, target int) bool {
	x, y := 0, len(plants[0])-1
	for x < len(plants) && y >= 0 {
		cur := plants[x][y]
		if cur > target {
			y--
		} else if cur == target {
			return true
		} else {
			x++
		}
	}
	return false
}
