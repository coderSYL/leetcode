// C++
// leetcode 735
// https://leetcode.cn/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    	int p = 1, top = 0, n = asteroids.size();
    	while (p < n) {
    		// 栈空，直接入
    		if(top == -1) {
    			asteroids[++top] = asteroids[p++];
    			continue;
    		}


    		if(asteroids[top] > 0 && asteroids[p] < 0) {
    			// 会撞
    			if (asteroids[p] + asteroids[top] < 0) {
    				// 新入的比较大，撞碎栈顶
    				top--;
    			} else if (asteroids[p] + asteroids[top] == 0) {
    				// 一样大，一起碎
    				top--;
    				p++;
    			} else {
    				// 栈顶比较大
    				p++;
    			}
    		} else {
    			// 不会撞
    			asteroids[++top] = asteroids[p++];
    		}
    	}

    	asteroids.resize(top + 1);
    	return asteroids;
    }
};