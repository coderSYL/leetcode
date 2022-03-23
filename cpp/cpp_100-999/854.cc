// C++
// leetcode 854
// https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
// 思路:
// 方法1: 一个个搞（可能因为本题数据量小，所以这个方法快点）
// 方法2: 二分

// 方法1-循环
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int size =arr.size();
//         int i =0;
//         while(arr[i] < arr[i+1])
//             i++;
//         return i;
//     }
// };

// 方法2-二分
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        int i = 0;
        int j = size - 1;
        int mid;
        while(i <= j){
            mid = i + (j-i) / 2;
            if(arr[mid-1] > arr[mid])
            {
                j = mid;
                continue;
            }
            else if(arr[mid+1] > arr[mid])
            {
                i = mid;
                continue;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};