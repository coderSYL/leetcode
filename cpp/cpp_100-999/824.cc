// C++
// leetcode 824
// https://leetcode-cn.com/problems/goat-latin/

class Solution {
public:
	bool isVowel(char a) {
		if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'||
				a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
			return true;
		return false;
	}

    string toGoatLatin(string sentence) {
    	vector<char> tmp;
    	int cnt = 2;
        int n = sentence.size();
    	for(int i = 0; i < n; ) {
            // cout<<i<<endl;
    		bool startWithVowel = isVowel(sentence[i]);
    		if(startWithVowel)
    			tmp.push_back(sentence[i]);
    		int j = i+1;
    		while(j < n && sentence[j] != ' ') {
    			tmp.push_back(sentence[j++]);
    		}
    		if(!startWithVowel)
    			tmp.push_back(sentence[i]);
    		tmp.push_back('m');
    		tmp.insert(tmp.end(), cnt++, 'a');
    		if(j<n)
    			tmp.push_back(' ');
    		i = j+1;
    	}
    	return string(tmp.begin(), tmp.end());
    }
};