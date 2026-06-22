pub fn map_word_weights(words: Vec<String>, weights: Vec<i32>) -> String {
    words.iter()
        .map(|w| {
            let sum = (w.chars().map(|c| (c as u8 - b'a') as usize)
                .map(|i| weights[i])
                .sum::<i32>()) % 26;
            return (b'a' + sum as u8) as char;
        }).collect::<String>()
}
