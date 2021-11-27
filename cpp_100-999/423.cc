// C++
// leetcode 423
// https://leetcode-cn.com/problems/reconstruct-original-digits-from-english/
// 通过找字符与数字之间的对应关系来确定数字的数量

class Solution {
public:
	// 得到字符对应的index，其中 'e' 对应 0，以此类推
	int getIdx(char a) {	return (int)(a - 'e'); }

    string originalDigits(string s) {
    	// 记录十个数字的个数
    	int num[10];
    	// 记录所有字母的数量，其中cnt[0]是'e'的数量
    	int cnt[22];
    	memset(num, 0, sizeof(num));
    	memset(cnt, 0, sizeof(cnt));
    	// 统计各字符数量
    	for(auto c : s)
    		cnt[getIdx(c)]++;
    	// 计算各个数字的个数
    	num[0] = cnt[getIdx('z')];
    	num[2] = cnt[getIdx('w')];
    	num[6] = cnt[getIdx('x')];
    	num[8] = cnt[getIdx('g')];
    	num[3] = cnt[getIdx('t')] - num[2] - num[8];
    	num[4] = cnt[getIdx('r')] - num[0] - num[3];
    	num[7] = cnt[getIdx('s')] - num[6];
    	num[1] = cnt[getIdx('o')] - num[0] - num[2] - num[4];
    	num[5] = cnt[getIdx('f')] - num[4];
    	num[9] = cnt[getIdx('i')] - num[5] - num[6] - num[8];
    	// 所有数字的个数的和，即答案string.size()
    	int sum = 0;
    	for(int i = 0; i < 10; i++)
    		sum += num[i];

    	vector<int>	tmp(sum,'0');
    	int idx = num[0], now = 0;
    	while(++now < 10) {
    		char c = '0' + now;
    		while(num[now] > 0) {
    			tmp[idx++] = c;
    			num[now]--;
    		}
    	}
    	return 	string(tmp.begin(), tmp.end());
    }
};