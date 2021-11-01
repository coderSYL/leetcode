// C++
// leetcode 260
// https://leetcode-cn.com/problems/single-number-iii/
// 


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    	vector<int>	res;
    	sort(nums.begin(), nums.end());
    	for(int i = 0; i < nums.size(); i++) {
    		if(i + 1 != nums.size() && nums[i] == nums[i + 1])
    			i++;
    		else
    			res.push_back(nums[i]);
    	}
    	return	res;
    }
};

// // 方法二：使用异或，更快，线性时间复杂度
// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         vector<int> res(2, 0);
//         int sum = 0;
//         for(auto x : nums)
//             sum ^= x;

//         // k为sum中的最高位
//         int k = -1;
//         for(int i = 31; i >= 0 && k == -1; i--)
//             if((sum>>i & 1) == 1)
//                 k = i;

//         for(auto x : nums) {
//             if((x >> k) & 1 == 1)
//                 res[0] ^= x;
//         }
//         res[1] = sum ^ res[0];
//         return  res;
//     }
// };