use std::collections::HashSet;
pub fn recover_order(order: Vec<i32>, friends: Vec<i32>) -> Vec<i32> {
    let set:HashSet<i32> = friends.into_iter().collect();
    let mut rs = Vec::new();
    for (_,v) in order.iter().enumerate() {
        if set.contains(v){
            rs.push(*v);
        }
    }
    rs
}
