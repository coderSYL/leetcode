// C++
// leetcode 393
// https://leetcode-cn.com/problems/utf-8-validation/

class Solution {
public:
	// 用于检测a的7、6位是否为10
	bool isHead10(int a)  {
		if(((a>>7)&1) == 0) return false;
		if(((a>>6)&1) == 1) return false;
		return true;
	}

	// 得到前置1的个数
	int getHeadOneNum(int a) {
		int res = 0;
		while(res < 8) {
			int pos = 7-res;
			if((a>>pos) & 1) res++;
			else break;
		}
		return res;
	}

    bool validUtf8(vector<int>& data) {
    	int n = data.size();
    	int p = 0;
    	while(p < n) {
    		int byteNum = getHeadOneNum(data[p]);
    		// cout<<p<<" : "<<byteNum<<endl;
    		if(byteNum == 0) {
    			p++;
    			continue;
    		}
            if(byteNum == 1 || byteNum > 4)
                return false;
    		if(p + byteNum > n)
    			return false;
    		int end = p + byteNum;
    		p++;
    		while(p < end) {
    			if(isHead10(data[p])) {
    				// cout<<"pos : "<<p<<" is good"<<endl;
                    p++;
                } else {
                	// cout<<"pos : "<<p<<" is bad"<<endl;
    				return false;
                }
    		}
    	}
    	return true;
    }
};