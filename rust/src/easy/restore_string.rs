pub fn restore_string(s: String, indices: Vec<i32>) -> String {
    let raw:Vec<char>= s.chars().collect();
    let mut rs = raw.clone();
    for i in 0..s.len() {
        let realIndex = indices[i];
        rs[realIndex as usize] = raw[i];
    }
    rs.into_iter().collect()
}