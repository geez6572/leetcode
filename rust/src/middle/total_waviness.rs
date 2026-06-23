pub fn total_waviness(num1: i32, num2: i32) -> i32 {
    let mut res = 0;
    for val in num1..=num2 {
        if val < 100 {
            continue;
        }
        let mut val = val;
        let mut cmp:[i32;3] = [0;3];
        cmp[1] = val % 10;
        val /= 10;
        cmp[2] = val % 10;
        val /= 10;
        while val > 0 {
            cmp[0] = cmp[1];
            cmp[1] = cmp[2];
            cmp[2] = val % 10;
            val /= 10;
            if (cmp[1] > cmp[0] && cmp[1] > cmp[2]) || (cmp[1] < cmp[2]) && (cmp[1] < cmp[0]) {
                res += 1;
            }
        }
    }
    res
}