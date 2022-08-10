// Go
// leetcode 761
// https://leetcode.cn/problems/special-binary-string/

func makeLargestSpecial(s string) string {
    candidates := sort.StringSlice{}
    for i, cur, last := 0, 0, 0; i < len(s); i++ {
        if s[i] == '1' {
            cur++
        } else {
            cur--
        }
        if cur == 0 {
            candidates = append(candidates, "1" + makeLargestSpecial(s[last + 1 : i]) + "0")
            last = i + 1
        }
    }
    sort.Sort(sort.Reverse(candidates))
    return strings.Join(candidates, "")
}