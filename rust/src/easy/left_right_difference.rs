pub fn left_right_difference(nums: Vec<i32>) -> Vec<i32> {
    let mut prefix_sum:Vec<i32> = vec![0;nums.len() +1];
    for (i, &num) in nums.iter().enumerate() {
        prefix_sum[i + 1] = prefix_sum[i] + num;
    }
    let mut result = vec![0; nums.len()];
    for i in 0..nums.len() {
        result[i] = (prefix_sum[i] - (prefix_sum[prefix_sum.len() - 1] - prefix_sum[i + 1])).abs();
    }
    result
}