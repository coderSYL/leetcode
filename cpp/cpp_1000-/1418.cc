// C++
// leetcode 1418
// https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant/
// 先统计，再制表


class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    	map<int, unordered_map<string,int> >	getOrderForTable;
    	set<string>  all;
    	for(auto &oneOrder : orders) {
    		int tableNum = stoi(oneOrder[1]);
    		string &item = oneOrder[2];
    		all.insert(item);
    		getOrderForTable[ tableNum ][ item ]++;
    	}


    	// 开始制表
    	int dishKind = all.size();
    	vector<vector<string>> res(getOrderForTable.size() + 1, vector<string>(dishKind+1, "0"));

        
    	// 第一行
    	res[0][0] = "Table";
    	int i = 1;
    	for(auto it = all.begin(); it != all.end(); ++it)
    		res[0][i++] = *it;

    	
    	// 其它行
    	int lineNum = 1;
    	for(auto it = getOrderForTable.begin(); it != getOrderForTable.end(); ++it) {
    		auto &m = it->second;
    		res[lineNum][0] = to_string(it->first);
    		for(i = 1; i <= dishKind; ++i) {
    			if(m[res[0][i]] == 0)
    				continue;
    			res[lineNum][i] = to_string(m[res[0][i]]);
    		}
    		++lineNum;
    	}
    	return res;
    }
};