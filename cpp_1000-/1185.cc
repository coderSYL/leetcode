// C++
// leetcode 1185
// https://leetcode-cn.com/problems/day-of-the-week/

class Solution {
public:
	// int -> string
	string s[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	// 平年到i+1月的1号之前有多少天
	int daysTillThisMonth[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	
    string dayOfTheWeek(int day, int month, int year) {
    	bool isBigYear = (year%4 == 0 && year % 100 != 0) || (year % 400 == 0);
    	int idx = 6;	// 1968年1月1日星期一，前一天星期天，在s[6]
    	year -= 1968;
    	idx += year / 4 * 5;	// 每4年多5天
    	year %= 4;
    	if(isBigYear && month > 2) ++idx;	// 当年是闰年且需要过2月29
    	idx += year + (year > 0 ? 1 : 0);
    	idx += daysTillThisMonth[month - 1] + day;
    	idx %= 7;
    	return	s[idx];
    }
};