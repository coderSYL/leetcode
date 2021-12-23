// C++
// leetcode 1154
// https://leetcode-cn.com/problems/day-of-the-year/

class Solution {
public:
	int daysTillThisMonth[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int dayOfYear(string date) {
    	int year = stoi(date.substr(0,4));
    	int month = stoi(date.substr(5,2));
    	int day = stoi(date.substr(8,2));
    	bool isLeapYead = (year % 4 == 0);
    	int nth = daysTillThisMonth[month - 1] + day;
    	if(isLeapYead && month > 2) ++nth;
    	return nth;
    }
};