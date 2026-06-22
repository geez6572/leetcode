pub fn gcd_of_odd_even_sums(n: i32) -> i32 {
    let sum = (n * 2) * (n * 2 + 1) / 2;
    let odd_sum = (sum - n)/2;
    let even_sum = (sum - odd_sum);
    for i in (1..odd_sum).rev() {
        if odd_sum % i == 0 && even_sum % i == 0 {
            return i;
        }
    }
    0
}

#[cfg(test)]
mod test {
    use crate::easy::gcd_of_odd_even_sums::gcd_of_odd_even_sums;

    #[test]
    fn test(){
        gcd_of_odd_even_sums(4);
    }
}
