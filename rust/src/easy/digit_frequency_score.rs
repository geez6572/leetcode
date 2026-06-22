use std::collections::HashMap;

pub fn digit_frequency_score(n: i32) -> i32 {
    let mut count_map:HashMap<i32,i32> = HashMap::new();
    let mut n = n;
    while n > 0 {
        let cur_digit = n % 10;
        *count_map.entry(cur_digit).or_insert(0) += 1;
        n = n / 10;
    }
    count_map.iter().fold(0, |acc,(key,count)| acc + key * count)
}