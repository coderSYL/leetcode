// C++
// leetcode 84
// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
// 单调栈，确保栈内元素都比新进栈的要小，要是大了，就可以掏出来结算，必要的话更新res
// 小技巧，开始先给h的结尾加个0，确保所有的都能结算

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0);
        int n = h.size();
        stack<int>  s;
        int res = 0;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && h[s.top()] > h[i]) {
                int tmp = s.top();
                s.pop();
                res = max(res, h[tmp] * (s.empty() ? i : i - s.top() -1));
            }
            s.push(i);
        }
        return  res;
    }
};