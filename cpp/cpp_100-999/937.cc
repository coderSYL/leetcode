// C++
// leetcode 937
// https://leetcode-cn.com/problems/reorder-data-in-log-files/

class Solution {
public:
	struct Info
	{
		string type;
		string content;
		Info(string a, string b) : type(a), content(b) {
		}
		bool operator<(const Info& a) const
		{
			if(content != a.content)
				return content < a.content;
			return type < a.type;
		}
	};

    vector<string> reorderLogFiles(vector<string>& logs) {
    	int n = logs.size();
    	vector<Info> tmp;
    	vector<int> numIndex;
    	for(int j = 0; j < n; j++) {
    		string &s = logs[j];
    		int i = 0;
    		while(s[i] != ' ')
    			i++;
    		char c = s[i+1];
    		if(c >= '0' && c<= '9')
    			numIndex.push_back(j);
    		else
    			tmp.push_back(Info(s.substr(0, i), s.substr(i + 1)));
    	}

    	sort(tmp.begin(), tmp.end());
    	vector<string> res;
    	for(auto &a : tmp) {
    		res.push_back(a.type + " " + a.content);
    	}
    	for(auto & idx : numIndex) {
    		res.push_back(logs[idx]);
    	}
    	return res;
    }
};