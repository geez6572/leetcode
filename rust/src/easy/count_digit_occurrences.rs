pub fn count_digit_occurrences(nums: Vec<i32>, digit: i32) -> i32 {
    let mut count = 0;
    for &i in &nums {
        let mut val = i;
        while val > 0 {
            let cur_digit = val % 10;
            if cur_digit == digit {
                count += 1;
            }
            val = val / 10;
        }
    }
    count
}