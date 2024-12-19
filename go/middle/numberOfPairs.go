package main

func numberOfPairs(nums1 []int, nums2 []int, k int) int64 {
	filter := map[int]int64{}
	max1 := 0
	for _, v := range nums1 {
		if v%k == 0 {
			filter[v/k]++
			max1 = max(max1, v/k)
		}
	}
	m := map[int]int64{}
	for _, v := range nums2 {
		m[v]++
	}
	var rs int64
	for key, v := range m {
		for i := key; i <= max1; i += key {
			if cnt, e := m[i]; e {
				rs += v * cnt
			}
		}
	}
	return rs
}
