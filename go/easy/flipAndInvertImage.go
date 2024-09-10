package main

func flipAndInvertImage(image [][]int) [][]int {
	for i := range image {
		left := 0
		right := len(image[i]) - 1
		for left < right {
			temp := image[i][left]
			image[i][left] = image[i][right]
			image[i][right] = temp
			if image[i][left] == 0 {
				image[i][left] = 1
			} else {
				image[i][left] = 0
			}
			if image[i][right] == 0 {
				image[i][right] = 1
			} else {
				image[i][right] = 0
			}
			left++
			right--
		}
		if left == right {
			if image[i][left] == 0 {
				image[i][left] = 1
			} else {
				image[i][left] = 0
			}
		}
	}
	return image
}
