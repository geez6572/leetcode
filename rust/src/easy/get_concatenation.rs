pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
    nums.iter().chain(nums.iter()).copied().collect::<Vec<i32>>()
}