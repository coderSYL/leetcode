// C++
// leetcode 821
// https://leetcode-cn.com/problems/shortest-distance-to-a-character/

// 方法一
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
    	int n = s.size();
    	vector<int> res(n, 100000);
    	int now = 10000;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == c) {
    			now = 0;
    		} else {
    			now++;
    		}
    		res[i] = min(res[i], now);
    	}
    	for(int i = n-1; i >= 0; i--) {
    		if(s[i] == c) {
    			now = 0;
    		} else {
    			now++;
    		}
    		res[i] = min(res[i], now);
    	}
    	return res;
    }
};

// 方法二，bfs
// class Solution {
// public:
//     vector<int> shortestToChar(string s, char c) {
//         int n = s.size();
//         vector<int> res(n, -1);
//         queue<int> q;

//         for(int i = 0; i < n; i++) {
//             if(s[i] == c) {
//                 res[i] = 0;
//                 q.push(i);
//             }
//         }
        
//         while(!q.empty()) {
//             int cur = q.front();
//             q.pop();
//             int l = cur-1, r = cur+1;
//             if(l != -1 && res[l] == -1) {
//                 res[l] = res[cur] + 1;
//                 q.push(l);
//             }
//             if(r != n && res[r] == -1) {
//                 res[r] = res[cur] + 1;
//                 q.push(r);
//             }
//         }
//         return res;
//     }
// };