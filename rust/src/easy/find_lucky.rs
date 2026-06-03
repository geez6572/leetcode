use std::cmp::max;
use std::collections::HashMap;

pub fn find_lucky(arr: Vec<i32>) -> i32 {
    let mut map:HashMap<i32,i32> = HashMap::new();
    for value in arr.iter() {
        *map.entry(*value).or_insert(0) += 1;
    }

    let mut flag = false;
    let mut ma = 0;
    for (&key, &value) in map.iter() {
        if key == value {
            if flag {
                ma = max(ma, key);
            }else{
                flag = true;
                ma = key;
            }
        }
    }

    if flag {
         return ma;
    }

    -1
}

#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_find_lucky() {
        find_lucky(vec![2,2,3,4]);
    }
}
