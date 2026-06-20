pub fn string_matching(words: Vec<String>) -> Vec<String> {
    let mut rs = Vec::with_capacity(words.len());
    for i in 0..words.len() {
        for j in 0..words.len() {
            if i != j && words[j].contains(&words[i]) {
                rs.push(words[i].clone());
            }
        }
    }
    rs
}
