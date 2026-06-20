pub fn max_freq_sum(s: String) -> i32 {
    let mut max_y = 0;
    let mut max_f = 0;
    let cs:Vec<u8> = s.bytes().collect();
    let mut count:Vec<i32> = vec![0;26];
    for (_,c) in cs.iter().enumerate() {
        let index = (c - b'a') as usize;
        count[index] += 1;
        if *c == 'a' as u8 || *c == 'e' as u8 || *c == 'i' as u8 || *c == 'o' as u8 || *c == 'u' as u8 {
            max_y = max_y.max(count[index]);
        }else{
            max_f = max_f.max(count[index]);
        }
    }
    max_y + max_f
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn it_works() {
        max_freq_sum(String::from("successes"));
    }
}
