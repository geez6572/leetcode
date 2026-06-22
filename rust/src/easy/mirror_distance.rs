pub fn mirror_distance(n: i32) -> i32 {
    (n - reverse(n)).abs()
}

pub fn reverse(n: i32) -> i32 {
    let mut res = 0;
    let mut n = n;
    while n > 0 {
        let cur_digit = n % 10;
        res = res * 10 + cur_digit;
        n = n / 10;
    }
    res
}
