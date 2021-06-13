/*
 * C++
 * leetcode 350
 * url: https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
 * 先给两个数组排序，然后确定相同的数字，与349不同的是，答案中可以出现重复的
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
                i++;
                if(i== size1)
                    break;
                else
                    val_i = nums1[i];
                // j指针往后走
                j++;
                if(j==size2)
                    break;
                else
                    val_j = nums2[j];
            }else if(val_i <val_j){
                i++;
                if(i== size1)
                    break;
                else
                    val_i = nums1[i];
            }else{
                j++;
                if(j==size2)
                    break;
                else
                    val_j = nums2[j];
            }
        }
        return ret;
    }
};