// C++
// leetcode 969
// https://leetcode-cn.com/problems/pancake-sorting/
// 从后往前，每次把剩余数里最大的归位，每次归位需要2或0次操作

class Solution {
public:
    void changeYtoX(vector<int>& a, vector<int>& res, int x, int y) {
        if(x > y) swap(x, y);
        // 此时，x<y，应该把a[x]的值移到a[y]处，其他无所谓
        // x+1,y+1
        res.push_back(x+1);
        res.push_back(y+1);
        int l = 0, r = x;
        while(l < r) {
            swap(a[l], a[r]);
            l++, r--;
        }
        l = 0, r = y;
        while(l < r) {
            swap(a[l], a[r]);
            l++, r--;
        }
    }

    vector<int> pancakeSort(vector<int>& a) {
        int n = a.size();
        vector<int> res;
        for(int i = n; i > 0; i--) {
            int index = 0;
            while(a[index] != i) index++;
            if(index == i - 1) continue;
            changeYtoX(a, res, index, i-1);
        }
        return res;
    }
};