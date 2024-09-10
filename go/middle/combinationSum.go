package main

func combinationSum(candidates []int, target int) [][]int {
	rs := make([][]int, 0)
	curPath := make([]int, 0)
	var backtrace func(cur, index int)
	backtrace = func(cur, index int) {
		if cur == 0 {
			rs = append(rs, append([]int{}, curPath...))
			return
		}
		for i := index; i < len(candidates); i++ {
			if cur < candidates[i] {
				continue
			}
			curPath = append(curPath, candidates[i])
			backtrace(cur-candidates[i], i)
			curPath = curPath[:len(curPath)-1]
		}
	}
	backtrace(target, 0)
	return rs
}
