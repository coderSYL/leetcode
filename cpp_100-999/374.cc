/*
 * C++
 * leetcode 374
 * url: https://leetcode-cn.com/problems/guess-number-higher-or-lower/
 * 经典二分法
 */

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is lower than the guess number
 *                1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        int mid = 0;
        while( l<=r){
            mid = l+ (r-l)/2;
            switch(guess(mid))
            {
                case -1:
                {
                    r = mid-1;
                    break;
                }
                case 1 :
                {
                    l = mid+1;
                    break;
                }
                case 0 :{
                    return mid;
                }
            }
        }   // end while
        return -1;   // error
    }
};