pub fn remove_trailing_zeros(num: String) -> String {
    let mut last = num.len() - 1;
    for (i,c) in num.chars().rev().enumerate() {
        if c != '0' {
            last = i;
            break;
        }
    }
    return num[0..last].to_string();
}

#[cfg(test)]
mod test{
    use super::*;

    #[test]
    fn test(){
        remove_trailing_zeros(String::from("51230100"));
    }

}