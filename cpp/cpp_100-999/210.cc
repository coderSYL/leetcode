// C++
// leetcode 210
// https://leetcode-cn.com/problems/course-schedule-ii/
// 小改了一下刚刚写的207的答案，同样是时空间都很差的屑方法

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    	bool iRelayj[numCourses][numCourses];
    	memset(iRelayj, 0, sizeof(iRelayj));
    	for(auto & p : prerequisites) {
    		iRelayj[p[0]][p[1]] = true;
    	}
    	bool finished[numCourses];
    	memset(finished, 0, sizeof(finished));
    	vector<int> done;
    	bool lastTurnLearnedSomething = true;
    	
    	while(done.size() < numCourses && lastTurnLearnedSomething) {
    		lastTurnLearnedSomething = false;
	    	for(int i = 0; i < numCourses; i++) {
	    		// 看一下课i能否学
	    		if(finished[i]) continue;	// 之前学过了
	    		bool canLearn = true;
	    		for(int j = 0; j < numCourses; j++) {
	    			if(iRelayj[i][j] == true) {
	    				canLearn = false;
	    				break;
	    			}
	    		}
	    		if(canLearn) {
	    			// 学课i
	    			lastTurnLearnedSomething = true;
	    			done.push_back(i);
	    			finished[i] = true;
	    			for(int j = 0; j < numCourses; j++) {
	    				iRelayj[j][i] = false;
	    			}
	    		}
	    	}
	    }
	    if(done.size() < numCourses) done.clear();
	    return done;
    }
};