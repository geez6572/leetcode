
pub fn max_coins(mut piles: Vec<i32>) -> i32 {
    piles.sort_unstable();
    let mut res = 0;
    let mut index = (piles.len() - 2) as i32;
    let mut count = 0;
    while index > 0 && count < piles.len() / 3{
        res += piles[index as usize];
        index -= 2;
        count += 1;
    }
    res
}

#[cfg(test)]
mod test{

    use super::*;
    #[test]
    pub fn test_final_string() {
        max_coins(vec![9,8,7,6,5,1,2,3,4]);
    }
}