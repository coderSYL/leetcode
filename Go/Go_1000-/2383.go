// Go
// leetcode 2383
// https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/

func minNumberOfHours(initialEnergy int, initialExperience int, energy []int, experience []int) int {
	n, expTrain := len(energy), 0
	for i := 0; i < n; i++ {
		initialEnergy -= energy[i]
		if initialExperience <= experience[i] {
			expTrain += experience[i] + 1 - initialExperience
			initialExperience = experience[i] + 1
		}
		initialExperience += experience[i]
	}

	if initialEnergy <= 0 {
		return expTrain + 1 - initialEnergy
	}

	return expTrain
}