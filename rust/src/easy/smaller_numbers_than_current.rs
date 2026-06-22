use std::collections::HashMap;

pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
    let mut arr:[i32; 101]  = [0;101];
    for (_,&num) in nums.iter().enumerate() {
        arr[num as usize] += 1;
    }
    let mut map:HashMap<i32,i32> = HashMap::new();
    let mut count = 0;
    for (index,&val) in arr.iter().enumerate() {
        map.insert(index as i32, count);
        count += val;
    }
    nums.into_iter().map(|num| map.get(&num).unwrap()).copied().collect()
}