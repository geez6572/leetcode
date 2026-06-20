use std::cmp::min;

pub fn max_side_length(mat: Vec<Vec<i32>>, threshold: i32) -> i32 {
    let mut prefix_sum: Vec<Vec<i32>> = vec![vec![0; mat[0].len() + 1]; mat.len() + 1];
    for i in 1..prefix_sum.len() {
        for j in 1..prefix_sum[i].len() {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1]
                - prefix_sum[i - 1][j - 1]
                + mat[i - 1][j - 1];
        }
    }
    let max_len = min(mat.len(), mat[0].len());
    let mut cur_max_len = 1;
    for i in 1..prefix_sum.len(){
        for j in 1..prefix_sum[i].len(){
            while cur_max_len <= max_len{
                if i + cur_max_len - 1 < prefix_sum.len() && j + cur_max_len - 1< prefix_sum[0].len() && cal(&prefix_sum,i,j,cur_max_len) <= threshold {
                    cur_max_len += 1;
                }else{
                    break;
                }
            }
        }
    }
    cur_max_len as i32
}

fn cal(mat: &Vec<Vec<i32>>, i: usize,j: usize,cur_max_len:usize) -> i32 {
    let cur_value = mat[i + cur_max_len - 1][j + cur_max_len - 1] + mat[i - 1][j - 1]
        - mat[i - 1][j + cur_max_len - 1]
        - mat[i + cur_max_len - 1][j - 1];
    cur_value
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn test_max_side_length() {
        let v = vec!
        [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]
            .into_iter().map(Vec::from).collect::<Vec<Vec<i32>>>();
        super::max_side_length(v, 4);
    }
}
