// c with stl(c++)
// 28
// https://leetcode-cn.com/problems/implement-strstr/
// 


class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 =haystack.size();
        int size2 =needle.size();
        if(size2 == 0)
            return 0;

        int nexthead =1;
        while(nexthead<size2){
            if(needle[nexthead] ==needle[0])
                break;
            nexthead++;
        }
        // cout<<nexthead<<endl;
        if( size2>size1)
            return -1;

        for(int i= 0; i<= size1 -size2; i++){
            // cout<<i<<endl;
            if(haystack[i] == needle[0]){
                int temp = i, j =0;
                while((j<size2)&&(haystack[temp] ==needle[j])){
                    temp++;
                    j++;
                }
                
                if(j==size2)
                    return i;
                if(nexthead<j){
                    i += nexthead-1;
                }else{
                    i += j-1;
                }

            }
        }
        return -1;
    }
};