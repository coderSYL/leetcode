/*
 * C++
 * leetcode 1744
 * url: https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
 * 根据candiesCount构造一个尺寸大1的long数组，用来装前缀和
 * 对每个queries项做一次判断，判断方法：
 * 算出到了favoriteDay的时候的最小与最大吃糖数
 * 用最小与最大数来与前缀和数组进行比对，然后得出判断的答案
 */

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    	vector<bool> ret;
    	int TypeSize = candiesCount.size();
    	// 构造前缀和数组
    	long before[TypeSize+1];
    	before[0] = 0;
    	for(int i =1; i<=TypeSize; i++){
    		before[i] = before[i-1] + candiesCount[i-1];
    	}
    	// 循环判断
    	int size = queries.size();
    	for(int i =0; i<size; i++){
    		int favoriteType = queries[i][0];
    		long MIN = queries[i][1] +1, MAX = MIN *queries[i][2], beforeForMax = before[favoriteType], beforeForMin = before[favoriteType+1];
    		if(MIN <= beforeForMin && MAX>beforeForMax)
    			ret.push_back(true);
    		else
    			ret.push_back(false);
    	}
    	return ret;
    }
};