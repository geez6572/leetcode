pub fn sort_matrix(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let row_count = grid.len();
    let col_count = grid[0].len();
    let mut grid = grid;
    for i in 0..row_count {
        let mut cur_row = i;
        let mut cur_col = 0;
        let mut nums:Vec<i32> = Vec::new();
        while cur_row < row_count && cur_col < col_count {
            nums.push(grid[cur_row][cur_col]);
            cur_col += 1;
            cur_row += 1;
        }
        cur_row -= 1;
        cur_col -= 1;
        nums.sort_unstable();
        for (r, c) in (0..=cur_row).rev().zip((0..=cur_col).rev()) {
            // 优雅地解包 nums
            if let Some(val) = nums.pop() {
                grid[r][c] = val;
            } else {
                break; // nums 空了，提前结束
            }
        }
    }

    for i in 1..row_count {
        let mut cur_row = 0;
        let mut cur_col = i;
        let mut nums:Vec<i32> = Vec::new();
        while cur_row < row_count && cur_col < col_count {
            nums.push(grid[cur_row][cur_col]);
            cur_col += 1;
            cur_row += 1;
        }
        cur_row -= 1;
        cur_col -= 1;
        nums.sort_unstable_by(|a, b| b.cmp(a));
        for (r, c) in (0..=cur_row).rev().zip((0..=cur_col).rev()) {
            // 优雅地解包 nums
            if let Some(val) = nums.pop() {
                grid[r][c] = val;
            } else {
                break; // nums 空了，提前结束
            }
        }
    }
    grid
}


#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_sort_matrix() {
        let grid = vec![vec![1,7,3],vec![9,8,2],vec![4,5,6]];
        println!("{:?}",sort_matrix(grid));
    }
}