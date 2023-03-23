// Go
// leetcode 1626
// https://leetcode.cn/problems/best-team-with-no-conflicts/

func bestTeamScore(scores []int, ages []int) int {
	n := len(scores)
	for i, score := range scores {
		scores[i] = getNum(ages[i], score)
	}
	sort.Ints(scores)
	res := 0
	for i := 0; i < n; i++ {
		ages[i] = 0
		age, score := getAgeAndScore(scores[i])
		for j := 0; j < i; j++ {
			ageJ, _ := getAgeAndScore(scores[j])
			if ageJ <= age {
				ages[i] = max(ages[i], ages[j])
			}
		}
		ages[i] += score
		res = max(res, ages[i])
		
	}
	return res
}

func getNum(age, score int) int {
	return score * 1001 + age
}

func getAgeAndScore(num int) (age int, score int) {
	return num%1001, num/1001
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}