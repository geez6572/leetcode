use std::fmt::format;
use std::string;

pub fn reverse_prefix(s: String, k: i32) -> String {
    let mut str = String::from(&s[0..k as usize]);
    let prefix = str.chars().rev().collect::<String>();
    format!("{}{}",prefix, &s[k as usize..])
}
