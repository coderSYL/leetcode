// C++
// leetcode 502
// https://leetcode-cn.com/problems/ipo/
// 两个方法，一个是自己想的，一个是参考别人的，最终用了参考别人的，因为比较简洁

// 自己的
// 设置两个优先队列
// 队列1: 按利润排，利润大的在前，相同利润的启动资金小的在前
// 队列2: 按照启动资金排，资金小的在前，作为副队列
// 全部项目按照启动资金是否大于现有资金装入队列1或者队列2
// 每次选一个项目的步骤：
// 队列2中不断读top，如果成本<=现有资金，则从2中移除，加到1中，直到2空或者项目成本过高
// 读top并删除，更新现有资金
// 选k次项目

// 别人的
// 用vector装项目，然后按成本排一次序，低成本在前
// 设置一个大顶优先队列q，把符合的项目的利润加到里面
// 每次选项目步骤：
// 从vector中把做得动的项目的利润加到q中
// 把q的top就是本次做的项目的利润，更新现有资金
// 选k次项目

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector< pair<int, int> >    v;  // < 启动资金, 利润>
        int n = profits.size();
        for(int i = 0; i < n; i++) {
            v.push_back(make_pair(capital[i], profits[i]));
        }
        sort(v.begin(), v.end());
        priority_queue<int>  q;

        int idx = 0;
        while(k > 0) {
            while(idx < n && v[idx].first <= w) {
                q.push(v[idx].second);
                idx++;
            }
            if(q.empty())
                break;
            w += q.top();
            q.pop();
            k--;
        }

        return  w;
    }
};