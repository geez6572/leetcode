package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func generateTreesRecur(s, e int) []*TreeNode {
	if s > e {
		return nil
	}
	allNodes := make([]*TreeNode, 0)
	for i := s; i <= e; i++ {
		leftNodes := generateTreesRecur(s, i-1)
		rightNodes := generateTreesRecur(i+1, e)
		for i := range leftNodes {
			for k := range rightNodes {
				cur := new(TreeNode)
				cur.Val = i
				cur.Left = leftNodes[i]
				cur.Right = rightNodes[k]
				allNodes = append(allNodes, cur)
			}
		}
	}
	return allNodes
}

func generateTrees(n int) []*TreeNode {
	return generateTreesRecur(1, n)
}
