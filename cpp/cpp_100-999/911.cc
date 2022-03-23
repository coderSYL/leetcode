// C++
// leetcode 911
// https://leetcode-cn.com/problems/online-election

class TopVotedCandidate {
public:
	// 用来记录投票时间结点
	vector<int> timeForCheck;
	// 用来记录结点的
	vector<int> winners;
	
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    	int n = persons.size();
    	winners.resize(n);
    	// 计数器及其初始化
    	int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        // 预处理类中的两个 vector
    	int tmpWinner = -1, maxTicket = 0;
    	for(int i = 0; i < n; i++) {
    		int luckyPerson = persons[i];
    		cnt[luckyPerson]++;
    		if(cnt[luckyPerson] >= maxTicket) {
    			tmpWinner = luckyPerson;
    			maxTicket = cnt[luckyPerson];
    		}
    		winners[i] = tmpWinner;
    	}
    	times.swap(timeForCheck);
    }
    
    int q(int t) {
    	// 二分法，找到离t最近的时间结点（且要小于等于 t）
    	int l = 0, r = winners.size() - 1;
    	while(l <= r) {
    		int mid = (l + r) / 2;
    		if(timeForCheck[mid] < t) {
    			l = mid + 1;
    		} else if(timeForCheck[mid] > t) {
    			r = mid - 1;
    		} else {
                l = mid + 1;
    			r = mid;
    		}
    	}
    	return winners[r];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */