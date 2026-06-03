pub fn reverse_degree(s: String) -> i32 {
    let mut sum: i32 = 0;
    let bs:Vec<u8> = s.bytes().collect();
    for (i,b) in bs.iter().enumerate() {
        sum += (b'z' - b + 1) as i32 * i as i32;
    }
    sum
}
