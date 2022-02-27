// C++
// leetcode 2045
// https://leetcode-cn.com/problems/second-minimum-time-to-reach-destination/

class Solution {
public:
	struct near
	{
		int first;
		int second;
		near(int a, int b) : first(a), second(b){}
		void update(int x) {
			if(x == a) return;
			if(x < a) {
				b = a;
				a = x;
				return;
			}
			if(x < b) {
				b = x;
				return;
			}
		}
	};
	
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
    }
};