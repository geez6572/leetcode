use std::cmp::max;
use std::collections::hash_set::Union;
use std::path::absolute;

pub fn subarray_sum(nums: Vec<i32>) -> i32 {
    let mut prefix_sum = vec![0; nums.len()];
    prefix_sum[0] = nums[0];
    let mut sum = prefix_sum[0];
    for i in 1..nums.len() {
        prefix_sum[i] += prefix_sum[i - 1] + nums[i];
        sum += prefix_sum[i] - prefix_sum[max(0,i as i32 - nums[i]) as usize]
    }
    sum
}