pub fn find_degrees(matrix: Vec<Vec<i32>>) -> Vec<i32> {
    matrix.iter().map(|row| row.iter().sum::<i32>()).collect::<Vec<i32>>()
}