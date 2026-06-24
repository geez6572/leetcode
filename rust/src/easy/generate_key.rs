use std::cmp::min;

pub fn generate_key(mut num1: i32,mut num2: i32,mut num3: i32) -> i32 {
    let mut res = 0;
    let mut increase = 1;
    for i in 0..4 {
        let cur = vec![num1, num2, num3].into_iter().map(|x| x % 10).min().unwrap();
        num1 = num1 / 10;
        num2 = num2 / 10;
        num3 = num3 / 10;
        res += cur * increase;
        increase *= 10;
    }
    res
}