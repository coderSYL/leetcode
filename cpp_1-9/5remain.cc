/*
 * C++
 * leetcode 5
 * url: https://leetcode-cn.com/problems/longest-palindromic-substring/
 */

class Solution {
public:
    int findmax(string s, int start, int end, int size){
        while(start>=0 && end<size){
            if(s[start] == s[end]){
                start--;
                end++;
            }
            else
                break;
        }
        if(start<0 || end ==size)
            return (end-start-1);
        return (end-start+1);
    }
    
    string longestPalindrome(string s) {
        int size =s.size();
        string ret_string;
        /// determinate the max palindrome of a positon
        /// start from position (0+size-1)/2
        int center = size-1, i = 0, full = size, what =0, max_global =0;
        int i_max_local=0, start = 0, end = 0;

        /// initial size = size, then -1 for every loop, min =1;
        while(full>=1){
            cout<<full<<endl;
            i = center-what;
            if(full%2 == 1){   // odd
                i_max_local = 1;
                start = i/2-1;
                end = i/2+1;
                   // end odd
            }else{    // even
                i_max_local = 0;
                start = i/2;
                end = i/2+1;
                while(start>=0 && end<size){
                    if(s[start] == s[end]){
                        i_max_local +=2;
                        start--;
                        end++;
                    }
                    else
                        break;
                }
            }   // end even
            if(i_max_local==full && full> max_global)
                return string(s,0,i_max_local);
            
            if(i_max_local>max_global){
                max_global = i_max_local;
                ret_string = string(s,start+1, end-1);
            }


            /// 2th part
            if(what==0){
                full--;
                what++;
                continue;
            }
            i = center +what;
            if(full%2 == 1){   // odd
                i_max_local = 1;
                start = i/2-1;
                end = i/2+1;
                while(start>=0 && end<size){
                    if(s[start] == s[end]){
                        i_max_local +=2;
                        start--;
                        end++;
                    }
                    else
                        break;
                }   // end odd
            }else{    // even
                i_max_local = 0;
                start = i/2;
                end = i/2+1;
                while(start>=0 && end<size){
                    if(s[start] == s[end]){
                        i_max_local +=2;
                        start--;
                        end++;
                    }
                    else
                        break;
                }
            }   // end even
            if(i_max_local==full && full> max_global)
                return string(s, size-i_max_local,size);
            
            if(i_max_local>max_global){
                max_global = i_max_local;
                ret_string = string(s,start+1, end-1);
            }

            full --;
            what++;
        }
        cout<<ret_string;
        return ret_string;
    }
};


"cbababcbcabca"