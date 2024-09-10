package main

type CQueue struct {
	queue []int
}

func Constructor() CQueue {
	var rs CQueue
	rs.queue = make([]int, 0)
	return rs
}

func (this *CQueue) AppendTail(value int) {
	this.queue = append(this.queue, value)
}

func (this *CQueue) DeleteHead() int {
	if len(this.queue) == 0 {
		return -1
	}
	rs := this.queue[0]
	this.queue = this.queue[1:]
	return rs
}
