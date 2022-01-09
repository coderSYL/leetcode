// C++
// leetcode 1629
// https://leetcode-cn.com/problems/slowest-key/

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    	char res = keysPressed[0];
    	int longest = releaseTimes[0];
    	int n = releaseTimes.size();
    	for(int i = 1; i < n; ++i) {
    		int cur = releaseTimes[i] - releaseTimes[i - 1];
    		if(cur > longest) {
    			longest = cur;
    			res = keysPressed[i];
    		} else if (cur == longest){
    			res = max(keysPressed[i], res);
    		}
    	}
    	return res;
    }
};