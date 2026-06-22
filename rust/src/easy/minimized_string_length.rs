pub fn minimized_string_length(s: String) -> i32 {
    let mut ans = 0;
    for i in 'a'..='z' {
        if s.contains(i) {
            ans += 1;
        }
    }
    ans
}