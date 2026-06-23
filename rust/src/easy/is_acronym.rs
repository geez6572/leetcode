use std::str::Chars;

pub fn is_acronym(words: Vec<String>, s: String) -> bool {
    let s:Vec<char> = words.iter().map(|word| word.chars().next().unwrap()).collect();
    let s:String = words.iter().map(|word| word.chars().next().unwrap()).collect();
    true
}