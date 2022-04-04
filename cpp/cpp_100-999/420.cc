// C++
// leetcode 420
// https://leetcode-cn.com/problems/strong-password-checker/

class Solution {
public:
	bool isSmall(char &c) {
		if(c <= 'z' && c >= 'a')
			return true;
		return false;
	}

	bool isBig(char &c) {
		if(c <= 'Z' && c >= 'A')
			return true;
		return false;
	}

	bool isNumber(char &c) {
		if(c <= '9' && c >= '0')
			return true;
		return false;
	}

    int strongPasswordChecker(string password) {
    	char before = '?';
    	int cnt = 0;
    	vector<int> lian;
    	bool haveSmall = false, haveBig = false, haveNumber = false;
    	int n = password.size();
    	for(int i = 0; i < n; i++) {
    		char c = password[i];
    		if(c == before) {
    			cnt++;
    		} else {
    			before = c;
    			if(cnt >= 3)
    				lian.push_back(cnt);
    			cnt = 1;
    		}
    		if(isNumber(c)) {
    			haveNumber = true;
    		}else if (isSmall(c)) {
    			haveSmall = true;
    		} else if(isBig(c)) {
    			haveBig = true;
    		}
    	}
        if(cnt >= 3)
            lian.push_back(cnt);
    	cnt = 0;
    	if(!haveSmall) cnt++;
    	if(!haveBig) cnt++;
    	if(!haveNumber) cnt++;
    	int res = 0;
    	if(n > 20) {
    		// 删
    		res += n - 20;
    	}
    	int jian = res;
    	int sum = 0;	// 增，改，不能删
    	for(auto &x : lian) {
    		if(x % 3 == 0 && jian > 0) {
    			jian--;
    			x--;
    		}
    		
    	}
    	for(auto &x : lian) {
    		if(x % 3 == 1 && jian > 1) {
    			jian -= 2;
    			x -= 2;
    		}
    	}
    	for(auto &x : lian) {
    		if(x % 3 == 2 && jian > 2) {
    			jian -= 3;
    			x -= 3;
    		}
    		int operations = x/3;
    		while(operations > 0 && jian > 3) {
    			jian -= 3;
    			operations--;
    		}
    		sum += operations;
    	}
        // cout<<n<<endl;
        // cout<<sum<<endl;
    	if(n < 6) {
    		sum = max(sum, 6-n);
    	}
    	res += max(sum, cnt);
    	return res;
    }
};
