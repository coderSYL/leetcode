// C++
// leetcode 458
// https://leetcode-cn.com/problems/poor-pigs/

#include <cmath>
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    	int round = minutesToTest / minutesToDie;
    	return	(int) ceil(log(buckets) / log(round + 1));
    }
};