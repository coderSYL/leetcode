/*
 * C++
 * leetcode 1049
 * url: https://leetcode-cn.com/problems/last-stone-weight-ii/
 * 计算石头总量，除以二就是需要的子集的和，记为target
 * 用can[i]表示是否有子集和为[i]，i的范围为[0, target]
 * 超出target的不用记录，因为它的补集必在[0,target]中
 * 登记完毕后找离target最近的能达到的i， 2*(target-i) + (total%2)就是答案了
 */

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int size =stones.size(), total =0;
        for(int x:stones){
            total += x;
        }
        vector<int> t;
        int target = total/2, temp = 0;
        int can[target+1];  // [0, target]
        memset(can, 0, sizeof(can));
        can[0] =1;
        for(int i =0; i<size; i++){
            temp = stones[i];
            t.clear();  // 清空上次loop的零时装入数据
            for(int j =0; j<=target-temp; j++){
                if(can[j]){
                    // 用t来装本次loop需要装入的数值
                    // 需要统计完一个loop的才能一起登记到can里
                    // 不然可能会出现 stones[i]为1，给can[1]刚记为1，然后因为can[1]为1，把can[2]也登记了这样的循环登记
                    t.push_back(j+temp);    
                    
                }
            }
            for(int x:t){   // 一次装入
                can[x] =1;
            }
        }
        for(int i =target; i>=0; i--){
            if(can[i]==1){
                temp = 2*(target -i);
                break;
            }
        }
        if(total%2==1)
            temp++;
        return temp;
    }
};