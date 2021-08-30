// C++
// leetcode 881
// https://leetcode-cn.com/problems/boats-to-save-people/
// 

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0, j = n - 1;
        int res = 0;
        while(i <= j) {
            if(i==j)    return  ++res;
            if(people[i] + people[j] > limit) {
                j--;
                res++;
            } else {
                i++;
                j--;
                res++;
            }
        }
        return  res;
    }
};