use std::cmp::max;

pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
    let mut cur = 0;
    let mut ans = 0;
    for &x in &nums {
        if x == 1 {
            cur += 1;
            ans = max(ans, cur);
        }else{
            cur = 0;
        }
    }
    ans
}