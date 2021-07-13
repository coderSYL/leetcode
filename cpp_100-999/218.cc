// C++
// leetcode 218
// https://leetcode-cn.com/problems/the-skyline-problem
// 偷三叶的方法，扫描



class Solution {
public:
	static auto cmp(pair<int,int> a, pair<int,int> b) {
		if(a.first != b.first)
			return a.first < b.first;
		return a.second < b.second;
	}


    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    	vector<vector<int>>	res;
    	// temp 用来记录关键点，比如一个楼的左点和右点
    	vector<pair<int,int>>	temp;
    	for(auto x : buildings) {
    		int l = x[0];
    		int r = x[1];
    		int height = x[2];
    		temp.push_back({l, -height});	// 左点记为负
    		temp.push_back({r, height});	// 右点记为正
    	}

    	sort(temp.begin(), temp.end(), cmp);

    	multiset<int, greater<int>> pq{0};

    	for(auto p : temp) {
    		int point = p.first;
    		int height = p.second;
    		int highest = *(pq.begin());
    		if(height < 0) {
    			// 左端点
    			height = -height;
    			pq.insert(height);
    			if(height > highest) {
    				res.push_back({point, height});
    			}
    		} else {
    			// 右端点
    			pq.erase(pq.find(height));
    			int h = *(pq.begin());
    			if(highest > h) {
    				res.push_back({point, h});
    			}
    		}
    	}
    	return res;
    }
};