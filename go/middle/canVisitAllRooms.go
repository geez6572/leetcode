package main

func canVisitAllRooms(rooms [][]int) bool {
	visited := make([]bool, len(rooms))
	queue := make([]int, 0)
	queue = append(queue, 0)
	visited[0] = true
	count := 1
	for len(queue) > 0 {
		cur := queue[0]
		queue = queue[1:]
		for i := range rooms[cur] {
			if !visited[rooms[cur][i]] {
				count++
				visited[rooms[cur][i]] = true
				queue = append(queue, rooms[cur][i])
			}
		}
	}
	return count == len(rooms)
}
