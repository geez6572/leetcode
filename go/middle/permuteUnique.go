package main

func permuteUnique(nums []int) [][]int {
	rs := [][]int{}
	swap := func(a, b int) {
		temp := nums[a]
		nums[a] = nums[b]
		nums[b] = temp
	}
	var dfs func(index int)
	dfs = func(index int) {
		if index == len(nums) {
			rs = append(rs, append([]int{}, nums...))
			return
		}
		m := map[int]bool{}
		for i := index; i < len(nums); i++ {
			if _, e := m[nums[i]]; e {
				continue
			}
			m[nums[i]] = true
			swap(i, index)
			dfs(index + 1)
			swap(i, index)
		}
	}
	dfs(0)
	return rs
}
