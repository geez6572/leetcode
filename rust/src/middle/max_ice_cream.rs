pub fn max_ice_cream(costs: Vec<i32>, coins: i32) -> i32 {
    let max_cost = *costs.iter().max().unwrap_or(&0);
    let min_cost = *costs.iter().min().unwrap_or(&0);
    let mut count = vec![0;(max_cost - min_cost) as usize];
    for cost in costs.iter() {
        count[(cost - min_cost) as usize] += 1;
    }

    let mut coins = coins;
    let mut ans = 0;
    for (i,&val) in count.iter().enumerate(){
        let cur_cost = (i as i32 + min_cost);
        if coins >  cur_cost * val {
            ans += val;
            coins -= cur_cost * val;
        }else {
            ans += coins / cur_cost;
            break
        }
    }
    ans
}
