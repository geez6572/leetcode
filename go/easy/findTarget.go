package main

var (
	m  map[int]int
	rs bool = false
)

func recur(root *TreeNode, k int) {
	if root == nil {
		return
	}
	if _, exist := m[root.Val]; exist {
		rs = true
		return
	}
	m[k-root.Val] = 1
	recur(root.Left, k)
	recur(root.Right, k)
}

func findTarget(root *TreeNode, k int) bool {
	rs = false
	m = make(map[int]int)
	recur(root, k)
	return rs
}
