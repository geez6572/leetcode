pub fn max_distinct(s: String) -> i32 {
    let mut count:[i32;26] = [0; 26];
    for &b in s.as_bytes() {
        count[(b - b'a') as usize] = 1;
    }
    let mut res = 0;
    for &val in count.iter() {
        if val != 0 {
            res += 1;
        }
    }
    res
}