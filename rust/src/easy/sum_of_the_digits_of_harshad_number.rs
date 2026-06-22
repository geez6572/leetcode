pub fn sum_of_the_digits_of_harshad_number(x: i32) -> i32 {
    let mut sum = 0;
    let mut reduce = x;
    while reduce > 0 {
        sum += reduce % 10;
        reduce /= 10;
    }
    if x % sum != 0{
        return -1;
    }
    sum
}