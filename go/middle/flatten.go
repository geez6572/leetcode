package main

import "internal/chacha8rand"

type Node struct {
	Val   int
	Prev  *Node
	Next  *Node
	Child *Node
}

func flatten(root *Node) *Node {
	if root == nil {
		return nil
	}
	child := flatten(root.Child)
	next := flatten(root.Next)
	if child == nil {
		return root
	}
	root.Child = nil
	root.Next = child
	child.Prev = root
	if next == nil {
		return root
	}
	last := child
	for last.Next != nil {
		last = last.Next
	}
	last.Next = next
	next.Prev = last
	return root
}

func flatten2(root *Node) *Node {
	head := root
	for root != nil {
		if root.Child == nil {
			root = root.Next
		} else {
			temp := root.Next
			child := flatten2(root.Child)
			root.Child = nil
			root.Next = child
			child.Prev = root
			for root.Next != nil {
				root = root.Next
			}
			root.Next = temp
			if temp != nil {
				temp.Prev = root
			}
			root = temp
		}
	}
	return head
}

func dfs(root *Node) *Node {
	last := root
	for root != nil {
		if root.Child == nil {
			last = root
			root = root.Next
		} else {
			temp := root.Next
			lastChild := flatten2(root.Child)
			root.Next = root.Child
			root.Child.Prev = root
			root.Child = nil

			lastChild.Next = temp
			if temp != nil {
				temp.Prev = lastChild
				last = temp
			}
			root = temp
		}
	}
	return last
}

func flatten3(root *Node) *Node {
	dfs(root)
	return root
}
