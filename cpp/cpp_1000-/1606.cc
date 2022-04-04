// C++
// leetcode 1606
// https://leetcode-cn.com/problems/find-servers-that-handled-most-number-of-requests/

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        // pair<int, int> for <endTime, serverNumber>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyServerQueue;
        vector<int> res{0};
        set<int> freeServer;
        for(int i = 1; i < k; i++)
            freeServer.insert(i);
        busyServerQueue.push(make_pair(arrival[0] + load[0], 0));
        vector<int> cnt(k, 0);
        cnt[0] = 1;
        int maxNow = 1;
        for(int i = 1; i < n; i++) {
            int arrivalTime = arrival[i];
            int endTime = arrivalTime + load[i];
            // 从队列中释放已经完成请求的服务器
            while(!busyServerQueue.empty() && busyServerQueue.top().first <= arrivalTime) {
                freeServer.insert(busyServerQueue.top().second);
                busyServerQueue.pop();
            }
            if(freeServer.empty())
                continue;
            auto it = freeServer.lower_bound(i % k);
            if(it == freeServer.end())
                it = freeServer.begin();
            int targetServer = *it;
            freeServer.erase(it);
            busyServerQueue.push(make_pair(endTime, targetServer));
            cnt[targetServer]++;
            if(cnt[targetServer] > maxNow) {
                maxNow = cnt[targetServer];
                res.clear();
                res.push_back(targetServer);
            } else if(cnt[targetServer] == maxNow) {
                res.push_back(targetServer);
            }
            // cout<<"request "<<i<<" to Server "<<targetServer<<endl;
        }
        // cout<<maxNow<<endl;
        return res;
    }
};