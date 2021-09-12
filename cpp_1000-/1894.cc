// C++
// leetcode 1894
// https://leetcode-cn.com/problems/find-the-student-that-will-replace-the-chalk/

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
    	int n = chalk.size();
    	int sum = 0;

    	// 如果k太大以至于要所有学生循环答题很多圈，会很浪费时间
    	// 所以先算一轮总共要多少粉笔，（如果可以的话）把k变小点
    	for(auto x : chalk) {
    		sum += x;
    		if(sum > k)	break;	// 当sum大于k的时候，说明k不能变小，中断计算，防止溢出
    	}
    	k %= sum;

    	int res = 0;
    	while(true) {
    		k -= chalk[res];
    		if(k < 0)
    			return	res;
    		res++;
    	}
    	return -1; // never
    }
};