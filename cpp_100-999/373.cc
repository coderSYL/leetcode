// C++
// leetcode 373
// https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/
// 我的方法略麻烦

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	sort(nums1.begin(), nums1.end());
    	sort(nums2.begin(), nums2.end());
    	priority_queue<int> q1;
    	for(int i = 0; i < k && i < nums1.size(); ++i) {
    		for(int j = 0; j < k && j < nums2.size(); ++j) {
    			q1.push(nums1[i] + nums2[j]);
    			if(q1.size() > k)
    				q1.pop();
    		}
    	}

    	int cut = q1.top();
    	int cnt = 0;
    	while(!q1.empty() && q1.top() == cut) {
    		cnt++;
    		q1.pop();
    	}
    	vector<vector<int>> res;
    	vector<int> tmp(2);

    	for(int i = 0; i < k && i < nums1.size(); ++i) {
    		for(int j = 0; j < k && j < nums2.size(); ++j) {
    			int x = nums1[i], y = nums2[j];
    			if(x + y < cut || (x+y == cut && cnt > 0)) {
    				if(x + y == cut) cnt--;
    				tmp[0] = x;
    				tmp[1] = y;
    				res.push_back(tmp);
                    if(res.size() == k) break;
    			}
    		}
            if(res.size() == k) break;
    	}
    	return res;
    }
};