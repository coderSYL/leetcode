// C++
// leetcode 1575
// https://leetcode-cn.com/problems/count-all-possible-routes/
// 


class Solution {
public:
    int MOD = (int) 1e9 + 7;
    vector<vector<int>> cache;  // 存记忆的
    int l, r;   // 有效左右边界
    int finish_;    // 结束点的index

    int dfs(vector<int>& ls, vector<int>& least, int now, int fuelLeft) {
        // 曾经算过，不用再算
        if(cache[now - l][fuelLeft] != -1)
            return  cache[now - l][fuelLeft];


        // 所剩燃料已经不满足最低要求，直接寄
        if(fuelLeft < least[now]) {
            cache[now - l][fuelLeft] = 0;
            return  0;
        }


        // 开始计算本次传入参数的复合条件的次数
        // 已经在目的地的话自带一次
        int sum = (now == finish_ ? 1 : 0);
        // 尝试向左开
        int p = now - 1;
        while(p >= l) {
            int fuelNext = fuelLeft - (ls[now] - ls[p]);
            if(fuelNext >= 0) {
                sum += dfs(ls, least, p, fuelNext);
                sum %= MOD;
            } else
                break;
            p--;
        }
        // 尝试向右开
        p = now + 1;
        while(p <= r) {
            int fuelNext = fuelLeft - (ls[p] - ls[now]);
            if(fuelNext >= 0) {
                sum += dfs(ls, least, p, fuelNext);
                sum %= MOD;
            } else
                break;
            p++;
        }
        // 计算完毕后录入结果至cache中
        cache[now - l][fuelLeft] = sum;
        return  sum;
    }


    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        int startLocation = locations[start];
        int finishLocation = locations[finish];
        int low = startLocation - fuel;
        int high = startLocation + fuel;
        sort(locations.begin(), locations.end());

        // 寻找左右边界，以及出发点和结束点的index
        l = 0;
        r = n - 1;
        while(l < n && locations[l] < low)
            l++;
        while(r >= 0 && locations[r] > high)
            r--;
        start = l;
        while(locations[start] != startLocation)
            start++;
        finish_ = l;
        while(finish_ <= r && locations[finish_] != finishLocation)
            finish_++;

        // 超过右边界说明无法到达目的地
        if(finish_ == r + 1)
            return  0;

        // 计算从有效区间的各个节点到目的地的最低限度fuel要求
        vector<int> leastFuel(n);
        for(int i = l; i <= r; i++) {
            leastFuel[i] = (finishLocation > locations[i] ? finishLocation - locations[i] : locations[i] - finishLocation);
        }
        
        // 给cache赋予空间
        cache = vector<vector<int>>(r - l + 1, vector<int>(fuel + 1, -1));
        return  dfs(locations, leastFuel, start, fuel);
    }
};