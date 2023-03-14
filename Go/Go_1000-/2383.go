// Go
// leetcode 2383
// https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/

func minNumberOfHours(initialEnergy int, initialExperience int, energy []int, experience []int) int {
	energySum, experienceTrained := 0, 0
	for _, e := range energy {
		energySum += e
	}

	curExp := initialExperience
	for _, exp := range experience {
		if curExp <= exp {
			experienceTrained += exp + 1 - curExp
			curExp = exp + 1
		}
		curExp += exp
	}
	
	if energySum >= initialEnergy {
		return experienceTrained + energySum + 1 - initialEnergy
	}
	return experienceTrained
}