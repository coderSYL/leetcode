// Go
// leetcode 187
// https://leetcode-cn.com/problems/repeated-dna-sequences/

func findRepeatedDnaSequences(s string) (res []string) {
	cnt := make(map[int]int)

	getNum:= make(map[byte]int)
	getNum['A'] = 0
	getNum['T'] = 1
	getNum['G'] = 2
	getNum['C'] = 3

	n := len(s)
	if n<11 {
		return res
	}

	cur := 0
	MOD := 1<<18
	for i:=0; i<9; i++ {
		cur = cur * 4 + getNum[s[i]]
	}

	for i:=9; i<n; i++ {
		cur = cur%MOD * 4 + getNum[s[i]]
		cnt[cur]++
		if cnt[cur] == 2 {
			res = append(res, s[i-9:i+1])
		}
	}

	return res
}