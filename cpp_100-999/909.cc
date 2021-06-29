// C++
// leetcode 909
// https://leetcode-cn.com/problems/snakes-and-ladders/
// BFS

class Solution {
public:
    unordered_map<int, int> portal;

    inline bool isInPortal(int x){ return (portal.find(x) != portal.end());}

    int snakesAndLadders(vector<vector<int>>& board) {
        int size = board.size();
        int SIZE = size * size;
        // set all portals
        for(int i = 0 ; i < SIZE; i++)
        {
            int a = i / size;
            int b = i % size;
            if(a % 2 == 1)
                b = (size - 1) - b;
            a = (size - 1) - a;
            int temp = board[a][b];
            if(temp > 0)    portal[i + 1] = temp;
        }
        // set initial state
        vector<bool> haveStep(SIZE + 1);
        haveStep[1] = true;
        queue<pair<int,int>> work;
        work.push({1, 0});
        // working
        while(!work.empty())
        {
            int thisTurn = work.front().first;
            int thisStep = work.front().second + 1;
            work.pop();
            for(int i = 1; i <= 6; i++)
            {
                int np = thisTurn + i;
                if(np > SIZE)   break;
                if(isInPortal(np))  np = portal[np];
                if(haveStep[np]) continue;
                haveStep[np] = true;
                if(np == SIZE)  return thisStep;
                work.push({np, thisStep});
            }   // end following 6 loop
        }   // end work loop
        return -1;
    }
};