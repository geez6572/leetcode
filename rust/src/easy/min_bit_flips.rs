pub fn min_bit_flips(start: i32, goal: i32) -> i32 {
    let mut res = start ^ goal;
    let mut count = 0;
    while res > 0 {
        count += (res & 1);
        res >>= 1;
    }
    count
}