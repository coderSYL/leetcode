// C++
// leetcode 1705
// https://leetcode-cn.com/problems/maximum-number-of-eaten-apples/
// 把优先队列的类型换成指针 Node* 的话，
// 因为可以直接修改队列的内容会变快一些，
// 但是使用空间也会多一些

class Solution {
public:
	struct Node
	{
		int expiredDay;
		int num;
		Node(int expiredDay, int num) : expiredDay(expiredDay) , num(num) {}
		// 默认的pq中大的在上，这题中需要 expiredDay 小的在上
		bool operator<(const Node& a ) const {
			return expiredDay > a.expiredDay;
		}
	};

    int eatenApples(vector<int>& apples, vector<int>& days) {
    	int n = apples.size();
    	priority_queue<Node> q;
    	int res = 0;
    	for(int i = 0; !(i >= n && q.empty()); i++) {
    		if(i < n && apples[i] != 0 && days[i] != 0) {
    			q.push(Node(i + days[i], apples[i]));
    		}
    		while(!q.empty() && (q.top().num <= 0 || q.top().expiredDay <= i))
    			q.pop();
    		if(!q.empty()) {
    			int expiredDay = q.top().expiredDay;
    			int num = q.top().num;
    			q.pop();
    			q.push(Node(expiredDay, num - 1));
    			res++;
    		}
    	}
    	return res;
    }
};