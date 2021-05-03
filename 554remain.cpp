/*
 * C++
 * leetcode554
 * url: https://leetcode-cn.com/problems/brick-wall/
 */

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
    	int size = wall[0].size(), LENGTH =0;
    	for(int i =0; i<size; i++){
    		LENGTH += wall[0][i];	// 这个时候已经定了
    	}
    	// cout<<"length"<<LENGTH<<endl;
    	size = wall.size();
    	for()
    	int ans[LENGTH];	// 0号位不干活
    	memset(ans,0,sizeof(ans));

    	
    	// cout<<size<<endl;
    	int k = 0, counter = 0,now = 0,before = 0, i=0;;
    	while(k<size){
    		int s = wall[k].size();
    		now = 0;
    		before = 0;
    		for(counter = 0; counter<s; counter++){
    			now += wall[k][counter];
    			for(i = before+1; i<now; i++){
    				ans[i]++;
    				// cout<<i<<"++"<<endl;
    			}
    			before = now;
    		}
    		k++;
    	}


    	now = size;
    	for( i =1; i<LENGTH; i++){
    		if(ans[i] < now)
    			now = ans[i];
    		// cout<<i<<":"<<ans[i]<<endl;
    	}
        if(now == INT_MAX)
            now = size;
    	return now;
    }
};

// others
public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> positions;
    int max_cnt = 0;
    for (const auto& bricks : wall) {
      int p = 0;
      for (int i = 0; i < bricks.size() - 1; ++i)
        max_cnt = max(max_cnt, ++positions[p += bricks[i]]);
    }
    
    return wall.size() - max_cnt;
  }
};

