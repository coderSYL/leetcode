// C++
// leetcode 457
// https://leetcode-cn.com/problems/circular-array-loop/
// 芜湖起飞，一个循环，利用原数组标记

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        bool positive = true;

        for(int i = 0; i < n; i++) {
            if(nums[i] > 1000 || nums[i] < -1000)
                continue;
            int loop = 1001 + i;

            if(nums[i] > 0) {
                positive = true;
            } else {
                positive = false;
            }

            int now = i;
            int step = nums[i];
            int next = ((now + step)%n + n) %n;
            step = nums[next];
            nums[i] = loop;
            while(true) {
                // cout<<"processing "<<next<<" step = "<<step<<endl;
                if(now == next)
                    break;
                if(step > 1000) {
                    if(step == loop)
                        return  true;
                    else
                        break;
                }
                if((step < 0 && positive) || (step > 0 && !positive))
                    break;
                now = next;
                next = ((now + step)%n + n) %n;
                step = nums[next];
                nums[now] = loop;
            }
        }
        return  false;
    }
};