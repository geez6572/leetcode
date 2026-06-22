use std::cmp::Ordering::Greater;

pub fn largest_local(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut result: Vec<Vec<i32>> = Vec::new();
    for i in 1..grid.len() - 1 {
        let mut row: Vec<i32> = Vec::new();
        for j in 1..grid[i].len() - 1 {
            let mut max = grid[i][j];
            for n in i-1..=i+1 {
                for k in j-1..=j+1 {
                    max = max.max(grid[n][k]).abs();
                }
            }
            row.push(max);
        }
        result.push(row);
    }
    result
}