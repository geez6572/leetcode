pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
    recur(&nums,0,0)
}

pub fn recur(nums: &Vec<i32>,s:usize,pre:i32) -> i32 {
    let sc = String::from("11");
    if s >= nums.len() {
        return 0;
    }
    let mut rs = 0;
    let mut pre = pre;
    for i in s..nums.len() {
        pre = pre ^ nums[i];
        rs += pre;
        rs += recur(&nums,s+1,pre.clone());
        pre = pre ^ nums[i];
    }
    rs
}
