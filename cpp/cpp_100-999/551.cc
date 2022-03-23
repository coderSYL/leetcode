// C++
// leetcode 551
// https://leetcode-cn.com/problems/student-attendance-record-i/
// 很老套的一次遍历

class Solution {
public:
    bool checkRecord(string s) {
    	int absentTimes = 0;
    	int lateCNT = 0;
    	for(auto c : s) {
    		if(c == 'A')
    			absentTimes++;
    		if(c == 'L') {
    			lateCNT++;
    		} else {
    			lateCNT = 0;
    		}
    		if(absentTimes == 2 || lateCNT == 3)
    			return	false;
    	}
    	return	true;
    }
};