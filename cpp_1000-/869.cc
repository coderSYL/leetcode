// C++
// leetcode 869
// https://leetcode-cn.com/problems/reordered-power-of-2/
//  


class Solution {
public:
    set<int> relative;

    void setRelative(int num) {
        // 寻找 num 位的2的指数幂，处理后加入relative

        // 选材范围定在[small, big]间
        // 例如 num = 2 时，为[10, 99]
        int small = 1;
        int i = 1;
        while(num > i) {
            small *= 10;
            i++;
        }
        int big = small * 10 -1;

        vector<int> tmp(num);
        i = 1;
        while(i < small)
            i *= 2;

        // 至此， i已经符合条件
        while(i <= big) {
            int copy = i;
            // 将每一个符合条件的好数都通过某种方式重组（排序，大的数字排前面），然后加入set relative 中
            int idx = 0;
            while(idx < num) {
                tmp[idx] = copy % 10;
                copy /= 10;
                idx++;
            }
            sort(tmp.begin(), tmp.end());
            while(idx > 0) {
                idx--;
                copy = copy * 10 + tmp[idx];
            }
            relative.insert(copy);
            // cout<<copy<<endl;
            i *= 2;
        }
    }


    bool reorderedPowerOf2(int n) {
        vector<int> v;
        while(n != 0) {
            v.push_back(n % 10);
            n /= 10;
        }
        setRelative(v.size());  // 根据位数设置relative
        sort(v.begin(), v.end());   // 原数排序
        for(int i = v.size() - 1; i >= 0; i--)
            n = n * 10 + v[i];  // 重组
        
        if(relative.find(n) == relative.end())  // 与relative比照
            return  false;
        return true;
    }
};