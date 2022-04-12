// C++
// leetcode 780
// https://leetcode-cn.com/problems/reaching-points/
// 自己想的%，但最后不知道咋收尾，看了三叶后明白了

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
    	while(tx > sx && ty > sy) {
    		if(tx > ty)
    			tx %= ty;
    		else
    			ty %= tx;
    	}
        if(tx < sx || ty < sy)
        	return false;
    	return (sx == tx ? (ty - sy) % sx == 0 : (tx - sx) % sy == 0);
    }
};