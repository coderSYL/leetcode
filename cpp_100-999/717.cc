// C++
// leetcode 717
// https://leetcode-cn.com/problems/1-bit-and-2-bit-characters/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(bits[n-1] == 1) return false;
        int numOneBeforeLastZero = 0;
        for(int i = n - 2; i >= 0 ; i--) {
            if(bits[i] == 1) numOneBeforeLastZero++;
            else break;
        }
        return (numOneBeforeLastZero % 2 == 0);
    }
};  