// Go
// leetcode 17
// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

var getBytes []string = []string{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}

var res []string
func dfs(s string, cur int, arr []rune) {
	if cur == len(arr) {
		res = append(res, string(arr))
		return
	}

	for _, b := range getBytes[int(s[cur] - '2')] {
		arr[cur] = b
		dfs(s, cur + 1, arr)
	}
}

func letterCombinations(digits string) []string {
	res = []string{}
	n := len(digits)
    if n == 0 {
        return res
    }
	tmp := make([]rune, n)
	dfs(digits, 0, tmp)
	return res
}