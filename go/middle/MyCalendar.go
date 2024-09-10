package main

type pair struct {
	start int
	end   int
}
type MyCalendar struct {
	cal []pair
}

func Constructor() MyCalendar {
	var rs MyCalendar
	rs.cal = make([]pair, 0)
	return rs
}

func (this *MyCalendar) Book(start int, end int) bool {
	for i := range this.cal {
		if start >= this.cal[i].end || end < this.cal[i].start {
			continue
		}
		return false
	}
	this.cal = append(this.cal, pair{start: start, end: end})
	return true
}
