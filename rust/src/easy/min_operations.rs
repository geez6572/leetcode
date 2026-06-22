use std::cmp::max;

pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
    let sum: i32 = nums.iter().sum();
    let a = max(1, 2);
    sum % k
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn it_works() {
        assert_eq!(min_operations(vec![1, 2, -2, -3, 4], 2), 3);
    }
}
