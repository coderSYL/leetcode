// Go
// leetcode 1598
// https://leetcode.cn/problems/crawler-log-folder/

func minOperations(logs []string) (res int) {
	for i := 0; i < len(logs); i++ {
		if logs[i] == "../" {
			if res != 0 {
				res--
			}
		} else if logs[i] != "./" {
			res++
		}
	}
	return res
}