use std::ascii::AsciiExt;

pub fn count_key_changes(s: String) -> i32 {
    let mut count = 0;
    let bytes = s.as_bytes();
    for i in 1..bytes.len() {
        let cur = bytes[i].to_ascii_lowercase();
        let prev = bytes[i - 1].to_ascii_lowercase();
        if cur == prev {
            count += 1;
        }
    }
    count
}