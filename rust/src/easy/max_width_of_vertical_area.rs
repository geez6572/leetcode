use std::cmp::max;

pub fn max_width_of_vertical_area(points: Vec<Vec<i32>>) -> i32 {
    let mut xs = points.iter().map(|x| x[0]).collect::<Vec<i32>>();
    xs.sort_unstable();
    xs.windows(2).map(|w| w[1] - w[0]).max().unwrap()
}
