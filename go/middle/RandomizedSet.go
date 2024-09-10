package main

import (
	"math/rand"
	"time"
)

type RandomizedSet struct {
	m map[int]int
	v []int
}

/** Initialize your data structure here. */
func Constructor() RandomizedSet {
	var rs RandomizedSet
	rs.m = make(map[int]int)
	rs.v = make([]int, 0)
	return rs
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
func (this *RandomizedSet) Insert(val int) bool {
	if _, e := this.m[val]; e {
		return false
	}
	this.v = append(this.v, val)
	this.m[val] = len(this.v) - 1
	return true
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
func (this *RandomizedSet) Remove(val int) bool {
	i, e := this.m[val]
	if !e {
		return false
	}
	last := this.v[len(this.v)-1]
	this.v[i] = last
	this.v = this.v[:len(this.v)-1]
	this.m[last] = i
	delete(this.m, val)
	return true
}

/** Get a random element from the set. */
func (this *RandomizedSet) GetRandom() int {
	randomInt := rand.Intn(len(this.v))

	return this.v[randomInt]
}
