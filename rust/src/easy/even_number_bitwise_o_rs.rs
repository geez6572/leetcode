pub fn even_number_bitwise_o_rs(nums: Vec<i32>) -> i32 {
    nums.iter()
        .filter(|&n| n & 1 == 0)
        .fold(0, |acc, &n| acc | n)
}
