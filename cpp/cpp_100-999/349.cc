/*
 * C++
 * leetcode 349
 * url: https://leetcode-cn.com/problems/intersection-of-two-arrays/
 * 先给两个数组排序，然后双指针法确定相同的数字
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int size1 = nums1.size(), size2 = nums2.size();
        if(size1 ==0 || size2==0)
            return ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i =0, j =0, val_i = nums1[0], val_j = nums2[0];
        while(true){
            if(val_i == val_j){
                // 符合的情况
                ret.push_back(val_i);
                // i指针往后走
                while(i < size1 && nums1[i] ==val_i)
                    i++;
                if(i==size1)
                    break;
                val_i = nums1[i];
                // j指针往后走
                while(j<size2   && nums2[j] == val_j)
                    j++;
                if(j ==size2)
                    break;
                val_j = nums2[j];
            }else if(val_i <val_j){
                while(i < size1 && nums1[i] ==val_i)
                    i++;
                if(i==size1)
                    break;
                val_i = nums1[i];
            }else{
                while(j<size2   && nums2[j] == val_j)
                    j++;
                if(j ==size2)
                    break;
                val_j = nums2[j];
            }
        }
        return ret;
    }
};