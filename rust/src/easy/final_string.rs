use std::collections::VecDeque;

pub fn final_string(s: String) -> String {
    let mut res: Vec<char> = vec![];
    let mut index = 0;
    let cs: Vec<char> = s.chars().collect();
    while index < cs.len() {
        let mut count_i = 0;
        while index < cs.len() && cs[index] == 'i' {
            count_i += 1;
            index += 1;
        }
        if count_i % 2 == 1{
            res.reverse();
            continue;
        }
        res.push(cs[index]);
        index += 1;
    }
    res.into_iter().collect()
}

pub fn final_string_2(s: String) -> String {
    let mut res:VecDeque<char> = VecDeque::new();
    let mut index = 0;
    let cs: Vec<char> = s.chars().collect();
    let mut positive = true;
    while index < cs.len() {
        while index < cs.len() && cs[index] == 'i' {
            positive = !positive;
            index += 1;
        }
        if index < cs.len() {
            if positive {
                res.push_back(cs[index]);
            }else {
                res.push_front(cs[index]);
            }
            index += 1;
        }
    }
    if positive {
        res.into_iter().collect()
    }else{
        res.into_iter().rev().collect()
    }
}

#[cfg(test)]
mod tests {
    use crate::easy::final_string::final_string;

    #[test]
    fn cells_in_range_test() {
        final_string(String::from("string"));
    }
}