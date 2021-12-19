// C++
// leetcode 1518
// https://leetcode-cn.com/problems/water-bottles/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
    	// 全喝了
    	int res = numBottles;
    	// 全变成空瓶
    	int emptyBottles = numBottles;
    	// 当空瓶还能换的时候
    	while(emptyBottles >= numExchange) {
    		// 能换get瓶
    		int get = emptyBottles / numExchange;
    		// 喝了get瓶
    		res += get;
    		// 此时剩的瓶子，如果够继续换
    		emptyBottles  = (emptyBottles % numExchange) + get;
    	}
    	return res;
    }
};

// // 数学方法：
// // 每 numExchange - 1 个空瓶可以换 一瓶量的酒（不带瓶）
// // 最后若只剩 numExchange - 1 瓶则不能换
// class Solution {
// public:
//     int numWaterBottles(int numBottles, int numExchange) {
//         int res = numBottles + numBottles / (numExchange - 1);
//         return (numBottles % (numExchange - 1) == 0 ? res - 1 : res);
//     }
// };