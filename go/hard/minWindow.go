package main

func minWindow(s string, t string) string {
	tm := make(map[byte]int)
	for i := range t {
		tm[t[i]]++
	}

	// 将窗口设置到满足条件的位置
	left := 0
	right := 0
	count := 0
	for right < len(s) {
		if _, e := tm[s[right]]; e {
			if tm[s[right]] > 0 {
				count++
			}
			tm[s[right]]--
		}
		right++
		if count == len(t) {
			break
		}
	}
	if count < len(t) {
		return ""
	}

	// 记录当前满足条件的窗口位置
	start := left
	end := right

	// 开始滑动窗口
	for left < right {
		if v, e := tm[s[left]]; !e { // 如果字符不存在于t中则跳过
			left++
		} else if v < 0 { // 如果字符存在于t中，但当前窗口有多余的该字符，减少该字符数量并跳过
			tm[s[left]]++
			left++
		} else { // 如果当前字符存在于t中，并且当前窗口不存在多余的该字符(即若左边界往右滑动一位会导致不满足条件)
			// 向右寻找字符用于弥补左边界向右滑动一位导致空缺的字符
			for right < len(s) {
				if s[right] == s[left] {
					break
				}
				// 增加窗口中新增的存在于t中的字符
				if _, e := tm[s[right]]; e {
					tm[s[right]]--
				}
				right++
			}
			// 未找到则直接返回
			if right == len(s) {
				break
			}
			right++
			left++
		}

		// 若是当前满足条件的窗口大小小于之前满足条件的窗口大小，则更新
		if right-left < end-start {
			start = left
			end = right
		}
	}
	return s[start:end]
}

func main() {
	minWindow("ADOBECODEBANC", "ABC")
}
