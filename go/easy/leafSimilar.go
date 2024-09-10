package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func recursion(root *TreeNode, seq []int) {
	if root == nil {
		return
	}
	if root.Left == nil && root.Right == nil {
		seq = append(seq, root.Val)
	}
	recursion(root.Left, seq)
	recursion(root.Right, seq)
}

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	var seq1 []int
	var seq2 []int
	recursion(root1, seq1)
	recursion(root2, seq2)
	if len(seq1) != len(seq2) {
		return false
	}
	for i := 0; i < len(seq1); i++ {
		if seq1[i] != seq2[i] {
			return false
		}
	}
	return true
}

func main() {
}
