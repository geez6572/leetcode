package main

import "fmt"

func sumDigitDifferences(nums []int) int64 {
	check := func(a, b int) int64 {
		var rs int64 = 0
		for a > 0 && b > 0 {
			if a%10 != b%10 {
				rs++
			}
			a = a / 10
			b = b / 10
		}
		return rs
	}
	var rs int64 = 0
	for i := 0; i < len(nums); i++ {
		for k := i + 1; k < len(nums); k++ {
			rs += check(nums[i], nums[k])
		}
	}
	return rs
}

func sumDigitDifferences2(nums []int) int64 {
	var rs int64 = 0
	for nums[0] > 0 {
		record := make([]int64, 10)
		for i := range nums {
			record[nums[i]%10]++
			nums[i] = nums[i] / 10
		}
		for i := range record {
			rs += record[i] * (int64(len(nums)) - record[i])
		}
	}
	return rs / 2
}

func main() {
	nums := []int{13, 23, 12}
	rs := sumDigitDifferences2(nums)
	fmt.Println(rs)
}
