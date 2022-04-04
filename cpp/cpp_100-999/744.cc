// C++
// leetcode 744
// https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
    	int n = letters.size();
    	int l = 0, r = n-1;
    	while(l <= r) {
    		int mid = (l + r)>>1;
    		if(letters[mid] <= target) {
    			l = mid +1;
    		} else {
    			r = mid - 1;
    		}
    	}
    	return letters[l] > target ? letters[l] : letters[0];
    }
};