/*
 * C++
 * leetcode 790
 * url: https://leetcode-cn.com/problems/domino-and-tromino-tiling/
 * n<=2直接返回结果
 * n>=3计算方法：
 * 使用动态规划，并且用两个数组共同完成计算，dp_sym[i]存储对称的图案数量，dp_asym[i]存储不对称的图案数量
 * 对于不同的n，我们称不能拆成更小的图案种类为原生种类，比如：
    * n = 1 XX     
      为对称原生

    * n = 2 X X    概念解释：两个横着个XX，即  XX ，可以拆分成两个原生的n=1的XX，所以不能算原生种类
            X X                           
      为对称原生                             XX

    * n = 3 XX  XX
            X    X
             X  X
            XX  XX
      为非对称原生
    * 对于n >= 3，都有两种 非对称的原生种类（找规律）
 * 每次计算dp[i]，利用：
    对称 + 非对称 = 非对称
    对称 + 对称 = 对称
    非对称+非对称 =非对称
    用j遍历1 ~i-1，每次用dp[j]与 原生[i-j]进行排列组合 j + (i-j) =j
 */

// class Solution {
// public:
//     int numTilings(int n) {
//     	if(n==1)
//     		return 1;
//     	if(n==2)
//     		return 2;
//     	long dp_sym[n+1] ,dp_asym[n+1], origin =0;
//         // set initial data for 1 and 2
//     	dp_sym[1] = 1;
//     	dp_asym[1] = 0;
//     	dp_sym[2] = 2;
//     	dp_asym[2] = 0;
//         // calculate for i>=3
//     	for(int i =3; i<=n;i++){
//     		dp_sym[i] =0;
//     		dp_asym[i] = 2;
//     		for(int j =1; j<i; j++){
//     			if(j<=2){
//                     // 小于3时，原生只有1种，为对称
//     				dp_sym[i] = (dp_sym[i] + dp_sym[i-j])%1000000007;
//     				dp_asym[i] = (dp_asym[i] + dp_asym[i-j])%1000000007;
//     			}else{   
//                     // 大于等于3时，原生有两种，且为非对称
//     				dp_asym[i] = (dp_asym[i] + 2* (dp_asym[i-j]+dp_sym[i-j]))%1000000007;
//     			}
//     		}
//     	}
//     	return (dp_asym[n]+dp_sym[n])%1000000007;
//     }
// };


// 通过上面的方法，令dp[n] = dp_sym[n] + dp_asym[n]
// 利用dp[n] - dp[n-1]得出
// dp[n] = 2*dp[n-1] +dp[n-3]

class Solution {
public:
    int numTilings(int n) {
        if(n<=2)
            return n;
        if(n==3)
            return 5;
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i =4; i<=n; i++){
            dp[i] = ((2* dp[i-1])%1000000007+dp[i-3])%1000000007;
        }
        return dp[n];
    }
};