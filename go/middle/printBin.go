package main

func printBin(num float64) string {
	rs := []byte{}
	for num > 0 && len(rs) < 32 {
		num = num * 2
		cur := int(num)
		rs = append(rs, byte(cur+'0'))
		num -= float64(cur)
	}
	if num != 0.0 {
		return "ERROR"
	}
	return string(rs)
}
