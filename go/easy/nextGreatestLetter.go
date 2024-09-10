package main

func nextGreatestLetter(letters []byte, target byte) byte {
	var rs byte = letters[0]
	for i := range letters {
		if letters[i] > target {
			rs = letters[i]
			break
		}
	}
	return rs
}

func nextGreatestLetter2(letters []byte, target byte) byte {
	left, right := 0, len(letters)-1
	for left < right {
		mid := left + (right-left)/2
		if letters[mid] > target {
			right = mid
		} else {
			left = mid + 1
		}
	}
	if left == right && letters[left] > target {
		return letters[0]
	}
	return letters[0]
}
