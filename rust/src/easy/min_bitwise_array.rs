pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
    let mut rs = vec![-1; nums.len()];
    for (i, v) in nums.iter().enumerate() {
        let mut cur = 1;
        while *v & cur != 0 {
            cur = cur << 1;
        }
        while cur > 0 {
            let cur_rs = *v ^ cur;
            if cur_rs | (cur_rs + 1) == *v {
                rs[i] = cur_rs;
                break;
            }
            cur = cur >> 1;
        }
    }
    rs
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_bitwise_array() {
        min_bitwise_array(vec![2, 3, 5, 7]);
    }
}
