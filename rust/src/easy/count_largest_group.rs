use std::collections::HashMap;

pub fn count_largest_group(n: i32) -> i32 {
    let mut map:HashMap<i32,i32> = HashMap::new();
    let mut maxGroup = 0;
    for mut value in 1..n+1 {
        let mut sum = 0;
        while value > 0 {
            sum += value % 10;
            value = value / 10;
        }
        let count = map.entry(sum).or_insert(0);
        *count += 1;
        maxGroup = maxGroup.max(*count)
    }

    let mut rs =0;
    for &value in map.values() {
        if value == maxGroup {
            rs += 1;
        }
    }
    rs
}
