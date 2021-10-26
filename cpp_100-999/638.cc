// C++
// leetcode 638
// https://leetcode-cn.com/problems/shopping-offers/
// 


class Solution {
public:
    int res = INT_MAX;

    void backTrace(vector<int>& price, vector<vector<int>>& special, int idx, int money, vector<int>& cur) {
        if(idx == special.size()) {
            // 礼包做完了全套，结算
            int extra = 0;
            for(int i = 0; i < price.size(); i++) {
                extra += price[i] * cur[i];
            }
            res = min(res, money + extra);
            return;
        }


        // 购买
        vector<int>& sell = special[idx];
        int priceForThePack = sell[price.size()];
        int maxNumForThisPack = INT_MAX;
        for(int i = 0; i < price.size(); i++) {
            if(sell[i] != 0)
                maxNumForThisPack = min(maxNumForThisPack, cur[i] / sell[i]);
        }
        for(int bought = 0; bought <= maxNumForThisPack; bought++) {
            backTrace(price, special, idx+1, money, cur);

            for(int i = 0; i < price.size(); i++) {
                cur[i] -= sell[i];
            }
            money += priceForThePack;
        }


        // 退货退钱
        for(int i = 0; i < price.size(); i++) {
            cur[i] +=  sell[i] * (maxNumForThisPack + 1);
        }
        money -=priceForThePack * (maxNumForThisPack + 1);
    }


    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int special_size = special.size();
        vector<int> cur(needs);
        backTrace(price, special, 0, 0, cur);
        return  res;
    }
};