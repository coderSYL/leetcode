// Go
// leetcode 828
// https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/

func uniqueLetterString(s string) (res int) {
    n := len(s)
    l, r := make([]int, n), make([]int, n)
    for i := 0; i < n; i++ {
        x := i + 1
        for x < n && s[x] != s[i] {
            x++
        }
        l[i] = x - i
        if x != n {
            r[x] = x- i
        }
        if r[i] == 0 {
            r[i] = i + 1
        }
    }

    for i := 0; i < n; i++ {
        res += l[i] * r[i]
    }
    return res
}