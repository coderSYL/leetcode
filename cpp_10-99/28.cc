// C++
// leetcode 28
// https://leetcode-cn.com/problems/implement-strstr/
// 思路:
// 先对needle预处理，找到与首字母相同的字母的index，若没有则设为needle的长度
// 然后循环haystack的各个字母进行比对
// 如果一次不对，则通过对needle的预处理来跳过一些情况使得能够加速处理

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
        if(size2>size1)
            return -1;

        for(int i= 0; i<= size1 -size2; i++)
        {
            if(haystack[i] == needle[0])
            {
                // check if it's same
                int temp = i, j =0;
                while((j<size2)&&(haystack[temp] ==needle[j])){
                    temp++;
                    j++;
                }
                // same
                if(j==size2)
                    return i;
                if(nexthead<j){
                    i += nexthead-1;
                }else{
                    i += j-1;
                }

            }
        }
        return -1;  // not found
    }
};