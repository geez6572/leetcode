pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
    let mut nums = nums;
    for i in 0..nums.len() {
        while nums[i] != i as i32 + 1 {
            let cur = nums[i];
            let swap_val = nums[(cur - 1) as usize];
            if cur == swap_val {
                break
            }
            nums[(cur - 1) as usize] = cur;
            nums[i] = swap_val;
        }
    }
    for (i, &num) in nums.iter().enumerate() {
        if num != i as i32 + 1 {
            return vec![num,i as i32 + 1];
        }
    }
    vec![]
}
#[cfg(test)]
mod tests {
    use super::find_error_nums;

    #[test]
    fn case1() {
        println!("{:?}",find_error_nums(vec![8,7,3,5,3,6,1,4]));
    }

    #[test]
    fn case2() {
        assert_eq!(find_error_nums(vec![1, 1]), vec![1, 2]);
    }
}