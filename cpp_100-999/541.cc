// C++
// leetcode 541
// https://leetcode-cn.com/problems/reverse-string-ii/
// 一次循环

class Solution {
public:
    string reverseStr(string s, int k) {
    	int n = s.size();
    	char temp[n];
    	int i = 0;
    	while(i < n) {
    		int left = n - i ;
    		if(left <= k) {
    			// 情况1:剩余不多于k个
    			int j = n - 1;
    			while(i < n) {
    				temp[i] = s[j];
    				i++;
    				j--;
    			}
    			break;
    		} else if(left > k && left <= 2 * k) {
    			// 情况2:剩小于等于2k个
    			int j = 0;
    			int m = i + k - 1;
    			while(j < k) {
    				temp[i + j] = s[m];
    				j++;
    				m--;
    			}
    			i = i + j;
    			while(i < n) {
    				temp[i] = s[i];
    				i++;
    			}
    			break;
    		} else {
    			// 剩余大于2k个
    			int j = 0;
    			int m = i + k - 1;
    			while(j < k) {
    				temp[i + j] = s[m];
    				j++;
    				m--;
    			}
    			i = i + j;
    			while(i < n) {
    				temp[i] = s[i];
    				i++;
    			}
    		}
    	}

    	return	string(temp, temp + n);
    }
};