// C++
// leetcode 2383
// https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int expTrain = 0;
        for (int i = 0; i < n; i++) {
        	initialEnergy -= energy[i];
        	if (initialExperience <= experience[i]) {
        		expTrain += experience[i] - initialExperience + 1;
        		initialExperience = experience[i] + 1;
        	}
        	initialExperience += experience[i];
        }
        return expTrain + (initialEnergy > 0 ? 0 : 1 - initialEnergy);
    }
};