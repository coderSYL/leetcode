// C++
// leetcode 274
// https://leetcode-cn.com/problems/h-index/
// 简简单单排个序，有大到小的，然后就出来了

class Solution {
public:
	auto static cmp(int a, int b) {  return a > b;}

    int hIndex(vector<int>& citations) {
    	sort(citations.begin(), citations.end(), cmp);
    	int n = citations.size();

    	int h = 0;
    	for(h = 0; h < n; ++h) {
    		if(citations[h] < h + 1)
    			break;
    	}

    	return	h;
    }
};