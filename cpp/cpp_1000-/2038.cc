// C++
// leetcode 2038
// https://leetcode-cn.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size()-1;
        int alice = 0, bob = 0;
        for(int i = 1; i < n; i++) {
        	char c = colors[i];
        	if(c == 'A') {
        		if(colors[i - 1] == 'A' && colors[i + 1] == 'A')
        			alice++;
        	} else if(colors[i - 1] == 'B' && colors[i + 1] == 'B')
        		bob++;
        }
        return alice > bob;
    }
};