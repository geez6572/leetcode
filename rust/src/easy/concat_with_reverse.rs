pub fn concat_with_reverse(nums: Vec<i32>) -> Vec<i32> {
    let a = nums.iter();
    nums.iter().chain(nums.iter().rev()).copied().collect()
}