// C++
// leetcode 630
// https://leetcode-cn.com/problems/course-schedule-iii/
// 用小顶pq存信息，用大顶pq存已经目前决定要上的课的时长

class Solution {
public:
    int MOD = 16384;    // 1<<14
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        priority_queue<int, vector<int>, greater<int> > pq;
        priority_queue<int, vector<int>, less<int>> chosen;
        int time = 0;
        for(int i = 0 ; i < n; i++)
            pq.push((courses[i][1]<<14) + courses[i][0]);
        while(!pq.empty()) {
            int duration = pq.top() % MOD;
            int endDay = pq.top()>>14;
            pq.pop();
            if(time + duration <= endDay) {
                chosen.push(duration);
                time += duration;
            } else if(!chosen.empty() && chosen.top() > duration) {
                time += duration - chosen.top();
                chosen.pop();
                chosen.push(duration);
            }
        }
        return chosen.size();
    }
};

// // 方法二
// // 差别，方法一用pq存信息，方法二用数组存信息
// class Solution {
// public:
//     int MOD = 16384;    // 1<<14
//     int scheduleCourse(vector<vector<int>>& courses) {
//         int n = courses.size();
//         int info[n];
//         priority_queue<int, vector<int>, less<int>> chosen;
//         int time = 0;
//         for(int i = 0 ; i < n; i++)
//             info[i] = (courses[i][1]<<14) + courses[i][0];
//         sort(info, info + n);
//         for(int i = 0; i < n; i++) {
//             int duration = info[i] % MOD;
//             int endDay = info[i]>>14;
//             if(time + duration <= endDay) {
//                 chosen.push(duration);
//                 time += duration;
//             } else if(!chosen.empty() && chosen.top() > duration) {
//                 time += duration - chosen.top();
//                 chosen.pop();
//                 chosen.push(duration);
//             }
//         }
//         return chosen.size();
//     }
// };