package main

func combinationSum2(candidates []int, target int) [][]int {
	cur := 0
	curPath := []int{}
	rs := [][]int{}
	var recur func(index int)
	recur = func(index int) {
		if cur == target {
			rs = append(rs, append([]int{}, curPath...))
			return
		}
		if cur > target || index == len(candidates) {
			return
		}

		for i := index; i < len(candidates); i++ {
			cur = cur + candidates[i]
			curPath = append(curPath, candidates[i])
			recur(i + 1)
			cur = cur - candidates[i]
			curPath = curPath[:len(curPath)-1]
		}
	}
	recur(0)
	return rs
}
