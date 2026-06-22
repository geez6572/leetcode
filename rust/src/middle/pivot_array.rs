use std::mem::swap;

pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
    let mut smaller:Vec<i32> = Vec::new();
    let mut eq:Vec<i32> = Vec::new();
    let mut greater:Vec<i32> = Vec::new();
    for &i in &nums {
        if pivot < i {
            smaller.push(i);
        }else if pivot > i {
            greater.push(i);
        }else {
            eq.push(i);
        }
    }
    greater.extend(eq);
    greater.extend(smaller);
    greater
}