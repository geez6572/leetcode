package main

import (
	"strconv"
)

type (
	TreeNode struct {
		Val   int
		Left  *TreeNode
		Right *TreeNode
	}
	Codec struct{}
)

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	if root == nil {
		return "{}"
	}
	left := this.serialize(root.Left)
	right := this.serialize(root.Right)
	rs := "{" + strconv.Itoa(root.Val) + "" + left + right + "}"
	return rs
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	index := 0
	var recur func() *TreeNode
	recur = func() *TreeNode {
		index++
		if data[index] == '}' {
			index++
			return nil
		}
		val := 0
		for data[index] != '{' {
			val = val*10 + int(data[index]-'0')
		}
		curNode := new(TreeNode)
		curNode.Val = val
		curNode.Left = recur()
		curNode.Right = recur()
		return curNode
	}
	rs := recur()
	return rs
}
