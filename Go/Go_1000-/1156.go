// Go
// leetcode 1156
// https://leetcode.cn/problems/swap-for-longest-repeated-character-substring/

func maxRepOpt1(text string) int {
	n := len(text)
	cnt := make([]int, 26)
	res := []int{0, 0}
	id := []int{0, 0}
	for i, j, next:=0, 0, 0; i < n;  {
		chance := 1
		for j<n {
			if text[j] == text[i] {
				j++
			} else if chance > 0 {
				chance--
				next = j
				j++
			} else {
				break
			}
			if chance > 0 {
				u := int(text[j-1]-'a')
				cnt[u]++
			}
		}
		if j-i > res[chance] {
			res[chance] = j-i
			id[chance] = int(text[i]-'a')
		}
        if chance > 0 {
            i = n
        } else {
            i, j = next, next
        }
	}
    // fmt.Println(res[0],res[1], cnt[id[1]])
	if res[1] < cnt[id[1]] {
		res[1]++
	}
    if res[0] > cnt[id[0]] {
        res[0]--
    }
	return max(res[0],res[1])
}

func min(a, b int) int {
	if a <b {
		return a 
	}
	return b
}

func max(a, b int) int {
	if a >b {
		return a 
	}
	return b
}