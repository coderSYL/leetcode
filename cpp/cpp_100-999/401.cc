// C++
// leetcode 401
// https://leetcode-cn.com/problems/binary-watch/
// 思路:
// 把灯数分成 小时灯 + 分钟灯
// 把对应的小时灯 与 分钟灯可能的数字算出来，然后排列组合搭配装进res里

class Solution {
public:
	vector<string> possibleHour(int lightNum){
		// 0～3 is good
		if(lightNum<0 || lightNum >3)	return {};
		vector<string> res;
		for(int i = 0; i < 12; i++)
		{
			int thisLight = 0;
			if(i & 1)	thisLight++;
			if(i & 2)	thisLight++;
			if(i & 4)	thisLight++;
			if(i & 8)	thisLight++;
			if(thisLight == lightNum)	res.push_back(to_string(i));
		}
		return res;
	}

	vector<string> possibleMinute( int lightNum){
		// 0~5 is good
		if(lightNum<0 || lightNum>5)	return {};
		vector<string> res;
		for(int i =0; i < 60; i++)
		{
			int thisLight = 0;
			if(i & 1)	thisLight++;
			if(i & 2)	thisLight++;
			if(i & 4)	thisLight++;
			if(i & 8)	thisLight++;
			if(i & 16)	thisLight++;
			if(i & 32)	thisLight++;
			if(thisLight == lightNum)	res.push_back( to_string(i));
		}
		for(auto& s : res)
		{
			if(s.size()<2)	s = "0" + s;
		}
		return res;
	}

    vector<string> readBinaryWatch(int turnedOn) {
    	vector<string> res;
    	for(int i =  0; i < 4; i++)
    	{
    		vector<string> Hour = possibleHour(i);
    		vector<string> Minute = possibleMinute(turnedOn-i);
    		for(auto h : Hour)
    		{
    			for(auto min : Minute)
    			{
    				res.push_back( h + ":" + min);
    			}
    		}
    	}
    	return res;
    }
};