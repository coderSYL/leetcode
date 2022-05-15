// C++
// leetcode 5
// https://leetcode-cn.com/problems/longest-palindromic-substring/
// 用 max_global 来记录 长度，good_l来记录起始位置
// 对每个i，分别用于奇数和偶数长度的子串向外进行扩张
// 每次扩张完就看是否能刷新 max_global 与 good_l


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
		int max_global = 0, good_l = 0;
        for(int i =0; i < n; i++){
        	// 奇数长度子串
    		int l = i, r = i;
    		while(l >= 0 && r < n && s[l] == s[r]) {
    			l--; r++;
    		}
    		if(r-l-1 > max_global) {
    			max_global = r-l-1;
    			good_l = l+1;
    		}
    		// 偶数长度子串
    		l = i; r = i+1;
    		while(l >= 0 && r < n && s[l] == s[r]) {
    			l--; r++;
    		}
    		if(r-l-1 > max_global) {
    			max_global = r-l-1;
    			good_l = l+1;
    		}
        }
        return s.substr(good_l, max_global);
    }
};
