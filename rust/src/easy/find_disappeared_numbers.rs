pub fn find_disappeared_numbers(nums: Vec<i32>) -> Vec<i32> {
    let mut count:Vec<i32> = vec![0;nums.len()];
    for &val in &nums {
        count[(val-1) as usize] += 1;
    }
    let mut ans: Vec<i32> = Vec::new();
    for (index,&val) in count.iter().enumerate() {
        if val == 0 {
            ans.push((index + 1) as i32);
        }
    }
    ans
}