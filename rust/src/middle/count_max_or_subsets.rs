
pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
    let mut max_val = nums[0];
    for &i in nums.iter() {
        max_val = max_val | i;
    }
    recur(&nums,0,0,max_val)
}

pub fn recur(nums: &Vec<i32>, cur_index: usize,cur_val:i32,max_val:i32) -> i32 {
    let mut res = 0;
    for i in cur_index..nums.len() {
        let next_val = cur_val | nums[i];
        if next_val == max_val {
            res += 1;
        }
        res += recur(nums,i + 1,next_val,max_val);
    }
    res
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn it_works() {
        count_max_or_subsets(vec![3,1]);
    }
}