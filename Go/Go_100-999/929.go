// Go
// leetcode 929
// https://leetcode.cn/problems/unique-email-addresses/

func numUniqueEmails(emails []string) int {
	// map 充当 set
	set := make(map[string]bool)

	// 遍历每个邮件地址，找到它送达的最终地址
	for _, s := range emails {
		n := len(s)
		buf := make([]byte, 0, n)
		get_at := false

		for i := 0; i < n; i++ {
			c := s[i]

			// 若已经在 @ 后，则直接加到 buf 中
			if get_at {
				buf = append(buf, c)
				continue
			}
			// 根据 s[i] 的不同，进行处理
			switch c {
				case '.' :
				case '+' :
						for s[i+1] != '@' {
							i++
						}
				case '@' :
						buf = append(buf, c)
						get_at = true
				default :
						buf = append(buf, c)
			}
		}
		set[string(buf)] = true
	}
	return len(set)
}