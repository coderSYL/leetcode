// C++
// leetcode offer 38
// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
// 思路:
// 先统计所有的字符和其数量
// 类里搞一些公共变量来存储上面一行说的东西
// 搞几个函数来操作这些数据结构

class Solution {
public:
	vector<string> res;
	char zimu[8];
	int num[8];
	int total = 8;
	int LEN;
	int asize = 0;
	string a;
	void beifen(char a[], int b[], int shu){	// a 与 b 保留zimu 与 num 的状态
		for(int i = 0; i<shu; i++)
		{
			a[i] = zimu[i];
			b[i] = num[i];
		}
	}

	void huigui(char a[], int b[], int shu){	// zimu 与 num 变成了 a 与 b 的形状
		for(int i = 0; i<shu; i++)
		{	
			zimu[i] = a[i];
			num[i]  = b[i];
		}
	}

	void zuo(int done){
		if(done == LEN)
		{
			res.push_back(a);
			return;
		}
		char lin[total];
		int shi[total];
		beifen(lin,shi,total);	// 存起来
		for(int i =0; i<total; i++)
		{
			if(num[i]>0)
			{
				num[i]--;
				a.push_back(zimu[i]);
				zuo(done+1);
				huigui(lin, shi, total);
				a.pop_back();
			}
		}
	}

    vector<string> permutation(string s){
    	LEN = s.length();
    	if(LEN == 0)	return res;
    	int next = 0;
    	bool flag = true;
    	for(int i = 0; i< LEN; i++)
    	{
    		flag = true;
    		for(int j = 0; j<next; j++)
    		{
    			if(zimu[j] == s[i]){
    				num[j]++;
    				flag = false;
    				break;
    			}
    		}
    		if(flag)
    		{
				zimu[next] = s[i];
				num[next] = 1;
				next++;
    		}
    	}	// 统计完毕
    	total = next;	// 把全局的长度标志给填上
    	zuo(0);
    	return res;
    }
};