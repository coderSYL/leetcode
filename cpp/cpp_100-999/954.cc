// C++
// leetcode 954
// https://leetcode-cn.com/problems/array-of-doubled-pairs/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
    	map<int, int> cnt;
    	for(auto &x : arr)
    		cnt[x]++;
    	for(auto &[k,v] : cnt) {
    		if(v == 0) 
                continue;
    		int target;
    		if(k <= 0) {
    			target = k / 2;
    			if(target * 2 != k)
                    return false;
    		} else {
    			target = 2 * k;
    		}
    		auto it = cnt.find(target);
    		if(it == cnt.end() || it->second < v)
    			return false;
    		it->second -= v;
            // cout<<"doing "<<k<<" target "<<target<<" left "<<cnt[target]<<endl;
    	}
    	return true;
    }
};