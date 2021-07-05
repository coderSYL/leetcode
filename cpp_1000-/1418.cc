// C++
// leetcode 1418
// https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant/
// 先统计，再制表


class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    	map<int, map<string,int> >	getOrderForTable;
    	set<string>  all;
    	for(auto &oneOrder : orders) {
    		int tableNum = stoi(oneOrder[1]);
    		string &item = oneOrder[2];
    		all.insert(item);
    		getOrderForTable[ tableNum ][ item ]++;
    	}

    	// 开始制表
    	vector<vector<string>> res;
    	// 第一行
    	vector<string> lineOne{"Table"};
    	for(auto it = all.begin(); it != all.end(); ++it) {
    		lineOne.push_back( *it );
    	}
    	res.push_back(lineOne);
    	int dishKind = all.size();
    	// 其它行
    	for(auto it = getOrderForTable.begin(); it != getOrderForTable.end(); ++it) {
    		auto &m = it->second;
    		vector<string> aline{ to_string(it->first) };
    		for(int i = 1; i <= dishKind; ++i) {
    			aline.push_back( to_string(m[lineOne[i]]) );
    		}
    		res.push_back(aline);
    	}
    	return res;
    }
};