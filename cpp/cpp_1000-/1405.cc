// C++
// leetcode 1405
// https://leetcode-cn.com/problems/longest-happy-string/

struct Info
	{
		char c;
		int cnt;
		Info(char c, int cnt) : c(c), cnt(cnt) {}
		// 小顶堆的排序： cnt大的优先出列
		bool operator<(const Info& a) const
		{
			return cnt < a.cnt;
		}
	};

class Solution {
public:
	string longestDiverseString(int a, int b, int c) {
		priority_queue<Info, vector<Info>> pq;
		if(a > 0) pq.push(Info('a', a));
		if(b > 0) pq.push(Info('b', b));
		if(c > 0) pq.push(Info('c', c));
		vector<char> tmp;
		int tmpCnt = 0;
		while(!pq.empty()) {
			char first = pq.top().c;
			int firstCnt = pq.top().cnt;
			int n = tmp.size();
			pq.pop();
			if(n >= 2 && tmp[n-1] == first && tmp[n-2] == first) {
				if(pq.empty()) break;
				char second = pq.top().c;
				int secondCnt = pq.top().cnt;
				pq.pop();
				tmp.push_back(second);
				if(secondCnt > 1) pq.push(Info(second, secondCnt - 1));
				pq.push(Info(first, firstCnt));
			} else {
				tmp.push_back(first);
				if(firstCnt > 1) pq.push(Info(first, firstCnt - 1));
			}
		}
		return string(tmp.begin(), tmp.end());
	}
};