pub fn count_partitions(nums: Vec<i32>) -> i32 {
    let mut suffixSum = nums.iter().sum::<i32>();
    let mut prefixSum = 0;
    let mut count = 0;
    for value in &nums {
        suffixSum -= value;
        prefixSum += value;
        if (suffixSum - prefixSum).abs() % 2 == 0{
            count += 1;
        }
    }
    count
}


