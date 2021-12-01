// C++
// leetcode 786
// https://leetcode-cn.com/problems/k-th-smallest-prime-fraction/
// 优先队列

class Solution {
public:
    struct Node {
        int x;
        int y;
        Node(int x, int y) : x(x), y(y) {}
        bool operator<(const Node& a) const {
            return x * a.y < y * a.x;
        }
    };

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<Node> pq;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                Node cur = Node(arr[i], arr[j]);
                if(pq.size() < k)
                    pq.push(cur);
                else if(cur < pq.top()) {
                    pq.pop();
                    pq.push(cur);
                }
            }
        }
        return  vector<int>{pq.top().x , pq.top().y};
    }
};