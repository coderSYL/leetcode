// C++
// leetcode 207
// https://leetcode-cn.com/problems/course-schedule/
// 很慢的屑方法

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	bool iRelayj[numCourses][numCourses];
    	memset(iRelayj, 0, sizeof(iRelayj));
    	for(auto & p : prerequisites) {
    		iRelayj[p[0]][p[1]] = true;
    	}
    	bool finished[numCourses];
    	memset(finished, 0, sizeof(finished));
    	int done = 0;
    	bool lastTurnLearnedSomething = true;
    	
    	while(done < numCourses && lastTurnLearnedSomething) {
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
	    			done++;
	    			finished[i] = true;
	    			for(int j = 0; j < numCourses; j++) {
	    				iRelayj[j][i] = false;
	    			}
	    		}
	    	}
	    }
	    return done == numCourses;
    }
};