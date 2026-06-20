pub fn min_costs(cost: Vec<i32>) -> Vec<i32> {
    let mut stack: Vec<i32> = Vec::new();
    for (_, v) in cost.iter().enumerate() {
        if stack.is_empty() || stack.last().unwrap() >= v {
            stack.push(*v);
        }
    }
    let mut rs: Vec<i32> = vec![0;cost.len()];
    for i in (0..cost.len()).rev() {
        let mut l = stack.last().unwrap();
        while *l > cost[i] {
            stack.pop();
            l = stack.last().unwrap();
        }
        rs.push(*l);
        if *l == cost[i] {
            stack.pop();
        }
    }
    rs
}