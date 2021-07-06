// C++
// leetcode 1711
// https://leetcode-cn.com/problems/count-good-meals/
// 先排序，再统计同分数的菜的数量
// 最后双指针计算答案

class Solution {
public:
	int countPairs(vector<int>& deliciousness) {
		int n = deliciousness.size();
		if(n == 1)
			return	0;
		sort(deliciousness.begin(), deliciousness.end());
		int MAX = log2(deliciousness[n - 2] + deliciousness[n - 1]);	// 最大的幂
		// 对 deliciousness 进行处理
		vector<long> num;
		{
			int p = 0;
			int q = 0;
			while(p < n) {
				int temp = deliciousness[p];
				long nn = 0;
				while(p < n) {
					if(deliciousness[p] != temp)
						break;
					++nn;
					++p;
				}
				deliciousness[q] = temp;
				++q;
				num.push_back(nn);
			}
			n = q;
		}


		int m = 0;		// 2 的 m 次幂
		int sum = 1;	// sum = 2 ^ m
		int res = 0;	// 记录答案
		while(m <= MAX) {
			// cout<<m<<endl;
			int i = 0;
			int j = n - 1;
			while(i <= j) {
				if(deliciousness[i] > sum)
					break;
				if(deliciousness[i] + deliciousness[j] == sum) {
					if(i == j) {
						res += (num[i] * (num[i] - 1) /2) % 1000000007;
						res %= 1000000007;
						// cout<<"add to "<<res<<endl;
						break;
					} else {
						res += (num[i] * num[j]) % 1000000007;
						res %= 1000000007;
					}
					++i;
					--j;
				} else if(deliciousness[i] + deliciousness[j] < sum) {
					++i;
				} else if(deliciousness[i] + deliciousness[j] > sum) {
					--j;
				}
			}
			sum *= 2;
			++m;
		}
		return res;
	}
};