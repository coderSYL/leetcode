// Go
// leetcode 207
// https://leetcode.cn/problems/course-schedule/

func canFinish(numCourses int, prerequisites [][]int) bool {
	after := make([][]int, numCourses)
	preNum := make([]int, numCourses)
	taken := make([]bool, numCourses)
	for _, p := range prerequisites {
		c, before := p[0], p[1]
		preNum[c]++
		after[before] = append(after[before], c)
	}

	cnt := 0
	for cnt < numCourses {
		cur := 0
		for i:=0; i< numCourses; i++ {
			if taken[i] { // 上过
				continue
			}

			if preNum[i] != 0 { // 还要上前置课程
				continue
			}

			// 上i课
			taken[i] = true
			for _, next := range after[i] {
				preNum[next]--
			}
			cur++
		}
		if cur == 0 {
			break
		}
		
		cnt+=cur
	}
	return cnt == numCourses
}