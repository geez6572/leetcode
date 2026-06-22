pub fn count_opposite_parity(nums: Vec<i32>) -> Vec<i32> {
    let n = nums.len();
    let mut res = vec![0i32; n];
    // count[0] = even count, count[1] = odd count
    let mut count = [0i32; 2];
    for i in (0..n).rev() {
        let parity = (nums[i] & 1) as usize;
        // opposite parity count is at index 1 - parity
        res[i] = count[1 - parity];
        count[parity] += 1;
    }
    res
}
