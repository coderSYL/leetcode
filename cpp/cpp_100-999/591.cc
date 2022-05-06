// C++
// leetcode 591
// https://leetcode-cn.com/problems/tag-validator/

class Solution {
public:
	bool is_big_letter(char c) {
		if(c >= 'A' && c <= 'Z')
			return true;
		return false;
	}

    bool isValid(string code) {
    	stack<string> tag_stk;
    	int n = code.size();
    	for(int i = 0; i < n; ) {
    		// tag_stk只能初始状态是空的，其他时候不行
    		if(tag_stk.empty() && (code[i] != '<' || i != 0)) {
    			return false;
    		}
    		// 找到第一个 <
    		while(i < n && code[i] != '<')
    			i++;
    		int j = i + 1;
    		// CDATA check
    		if(j + 7 < n && code.substr(j, 8) == "![CDATA[") {
    			j += 8;
    			bool have_an_end = false;
    			while(j < n) {
    				if(code[j] == ']') {
    					if(j + 2 >= n)
    						return false;
    					if(code[j+1] == ']' && code[j+2] == '>') {
    						// this CDATA part terminates
    						j += 2;
    						have_an_end = true;
    						break;
    					}
    				}
    				j++;
    			}
    			if(!have_an_end)
    				return false;
    			i = j+1;
    			continue;
    		}
    		// <> 的 check
    		if(j == n)
    			return false;
    		int left_cnt = 1;
    		bool out;
    		if(code[j] == '/') {
    			out = true;
    			i++;
    			j++;
    		} else {
    			out = false;
    		}

  	  		while(j < n && left_cnt != 0) {
  	  			char c = code[j];
  	  			if(c == '<') {
  	  				left_cnt++;
  	  			} else if(c == '>') {
  	  				left_cnt--;
  	  			}else if(!is_big_letter(c)) {
  	  				return false;
  	  			}
  	  			j++;
  	  		}
  	  		
  	  		if(left_cnt != 0)
  	  			return false;
  	  		int tmp_size = j-i-2;
            // cout<<tmp_size<<endl;
  	  		if(tmp_size <1 || tmp_size > 9)
  	  			return false;
  	  		string tmp = code.substr(i+1, tmp_size);
            // cout<<tmp<<endl;
  	  		if(out) {
  	  			if(tag_stk.empty() || tag_stk.top() != tmp)
  	  				return false;
  	  			tag_stk.pop();
  	  		} else {
  	  			tag_stk.push(tmp);
  	  		}
  	  		i = j;
    	}
    	return tag_stk.empty();
    }
};