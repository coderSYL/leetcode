// C++
// leetcode 496
// https://leetcode-cn.com/problems/next-greater-element-i/
// 先逆序处理nums2，维护一个单调栈，一直检查栈顶并pop，直到栈空或者找到一个比它大的元素，然后录入hashmap中


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int>  s;

        // 维护一个单调栈
        for(int i = nums2.size() - 1; i >= 0; i--) {
            int a = nums2[i];
            while(!s.empty()) {
                if(s.top() <= a)
                    s.pop();
                else {
                    m[a] = s.top();
                    break;
                }
            }
            s.push(a);
        }

        // 录入结果
        for(auto& x : nums1) {
            if(m.find(x) != m.end()) {
                x = m[x];
            } else {
                x = -1;
            }
        }

        return  nums1;
    }
};