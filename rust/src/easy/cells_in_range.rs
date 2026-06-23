pub fn cells_in_range(s: String) -> Vec<String> {
    let col_start = s.chars().nth(0).unwrap();
    let row_start = s.chars().nth(1).unwrap();
    let col_end = s.chars().nth(3).unwrap();
    let row_end = s.chars().nth(4).unwrap();
    let mut res:Vec<String> = Vec::new();
    for col in col_start..=col_end {
        for row in row_start..=row_end {
            res.push(format!("{}:{}", col, row));
        }
    }
    res
}