// C++
// leetcode 2299
// https://leetcode.cn/problems/strong-password-checker-ii/

class Solution {
public:
	// 小写，大写，数字，特殊
	bool need[4];


	string special = "!@#$%^&*()-+";
	
	bool isSpecial(char c) {
		for (char cc : special) {
			if (c == cc)
				return true;
		}
		return false;
	}

	void regist(char c) {
		if (c >= 'a' && c <= 'z')
			need[0] = true;
		else if (c >= 'A' && c <= 'Z')
			need[1] = true;
		else if (c >= '0' && c <= '9')
			need[2] = true;
		else if (!need[3] && isSpecial(c))
			need[3] = true;
	}

    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if (n < 8)
        	return false;
        memset(need, 0, sizeof(need));

        regist(password[0]);
        for (int i = 1; i < n; i++) {
        	if (password[i] == password[i - 1])
        		return false;
        	regist(password[i]);
        }
        for (int i = 0; i < 4; i++) {
        	if (!need[i])
        		return false;
        }
        return true;
    }
};