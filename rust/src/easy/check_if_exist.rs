use std::collections::HashSet;

pub fn check_if_exist(arr: Vec<i32>) -> bool {
    let mut set: HashSet<i32> = HashSet::new();
    for &value in &arr {
        if set.contains(&(value * 2)) {
            return true;
        }

        if value % 2 == 0 && set.contains(&(value / 2)) {
            return true;
        }

        set.insert(*value);
    }
    return false;
}
