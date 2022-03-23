// C++
// leetcode 42
// https://leetcode-cn.com/problems/trapping-rain-water/
// 单调栈的经典问题

class Solution {
public:
    int trap(vector<int>& h) {
    	int n = h.size();
    	int res = 0;
    	stack<int>	stack;
    	for(int i = 0; i < n; i++) {
    		while(!stack.empty() && h[stack.top()] < h[i]) {
    			int cur = stack.top();
    			stack.pop();

    			if(stack.empty())
    				continue;

    			int l = stack.top(), r = i;
    			int width = r - l - 1;
    			int height = min(h[l], h[r]) - h[cur];
    			res += width * height;
    		}
    		stack.push(i);
    	}
    	return	res;
    }
};