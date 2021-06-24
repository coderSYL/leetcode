// C++
// leetcode 149
// https://leetcode-cn.com/problems/max-points-on-a-line/
// 思路
// 解法1:
//  暴力，稍微剪点多余计算
//  时间复杂度根据不同情况不一样，总的来说在O(n^2)到O(n^3)之间
// 解法2:
//  固定i后算其它所有的斜率装入map
//  利用map统计包括点i的最大共线的点的数量
//  需要算gcd最大公约数
//  时间复杂度O(n^2 * log(m) )， n为点的数量， m为坐标差值的最大值
//  由于使用map时用了字符串及其拼接运算，故在线通过时间会因为测试用例较少而比解法1长不少

// C++
// leetcode 149
// https://leetcode-cn.com/problems/max-points-on-a-line/
// 思路

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
    	int PointNum = points.size();
    	if(PointNum <3)	return PointNum;
    	int CRITICAL = PointNum / 2;
    	int res = 2;
    	bool done[PointNum];
    	int x1 = 0;
    	int y1 = 0;
    	int Dx1 = 0;
    	int Dy1 = 0;
    	int Dx2 = 0;
    	int Dy2 = 0;
    	int local = 0;
    	for(int i = 0; i < PointNum; i++)
    	{
    		memset(done, 0, sizeof(done));
    		x1 = points[i][0];
    		y1 = points[i][1];
    		for(int j = i + 1; j < PointNum; j++)
    		{
    			if(done[j])	continue;
    			local = 2;
    			Dx1 = points[j][0] - x1;
    			Dy1 = points[j][1] - y1;
    			for(int k = j + 1; k <	PointNum; k++)
    			{
    				if(done[k])	continue;
    				Dx2 = points[k][0] - x1;
    				Dy2 = points[k][1] - y1;
    				if(Dx1 * Dy2 == Dx2 * Dy1)
    				{
    					done[k] = true;
    					local++;
    				}
    			}
    			if(local > res)
    			{
    				if(local > CRITICAL)	return local;
    				res = local;
    			}
    		}	// end j loop
    	}	// end i loop
    	return res;
    }
};


// 解法2
// class Solution {
// public:
// 	int gcd(int a, int b) {	return (b == 0)? a : gcd(b, a%b);}

//     int maxPoints(vector<vector<int>>& points) {
//     	int PointNum = points.size();
//     	if(PointNum <3)	return PointNum;
//     	int CriticalNum = PointNum / 2 + 1;
//     	int res = 2;
//     	bool done[PointNum];
//     	int x = 0;
//     	int y = 0;
//     	int Dx = 0;
//     	int Dy = 0;
//     	int divisor = 0;
//     	int local = 0;
//     	unordered_map<string, int> count;
//     	string oh;
//     	for(int i = 0; i < PointNum; i++)
//     	{
//     		count.clear();
//     		memset(done, 0, sizeof(done));
//     		x = points[i][0];
//     		y = points[i][1];
//     		for(int j = i + 1; j < PointNum; j++)
//     		{
//     			Dx = points[j][0] - x;
//     			Dy = points[j][1] - y;
//     			if(Dx == 0)	oh = "v";	// v means verticle
//     			else if(Dy ==0)	oh = "h";	// h means horizon
//     			else
//     			{
//     				divisor = gcd(Dx, Dy);
//     				Dx /= divisor;
//     				Dy /= divisor;
//     				oh = to_string(Dx) + ":" + to_string(Dy);
//     			}
//     			if(count.find(oh) == count.end())	count[oh] = 2;
//     			else	count[oh]++;
//     		}	// end j loop
//     		for(auto it = count.begin(); it != count.end(); it++)	res = max(res, it->second);
//     		if(res > CriticalNum)	return res;
//     	}	// end i loop
//     	return res;
//     }
// };