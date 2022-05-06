// C++
// leetcode 380
// https://leetcode-cn.com/problems/insert-delete-getrandom-o1/
// 偷三叶的思路

class RandomizedSet {
public:
	unordered_map<int, int> map;
	vector<int> nums;
	int idx;
    RandomizedSet() {
    	nums.resize(200010);
    	idx = -1;
    }
    
    bool insert(int val) {
    	// 存在
    	if(map.find(val) != map.end())
    		return false;
    	// 不存在，插入
    	nums[++idx] = val;
    	map[val] = idx;
    	return true; 
    }
    
    bool remove(int val) {
    	auto it = map.find(val);
    	if(it == map.end())
    		return false;
    	int pos = it->second;
    	int lastVal = nums[idx--];
    	nums[pos] = lastVal;
    	map[lastVal] = pos;
    	map.erase(it);
    	return true;
    }
    
    int getRandom() {
    	return nums[rand() % (idx+1)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */