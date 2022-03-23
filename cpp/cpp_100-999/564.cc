// C++
// leetcode 564
// https://leetcode-cn.com/problems/find-the-closest-palindrome/
// 自己写的一版考虑的情况太多了，最后按照三叶的思路写的呜呜呜

class Solution {
public:
	using ll = long long;
    string nearestPalindromic(string n) {
    	int len = n.size();
    	set<ll> set;
    	set.insert((ll)pow(10, len-1) -1 );
    	set.insert((ll)pow(10, len) + 1);
    	ll num = stoll(n);
        // cout<<num<<endl;
    	ll t = stoll(n.substr(0, (len+1) / 2));
    	for(int i = t-1; i <= t+1; i++) {
    		ll tmp = getNum(i, len % 2 == 0);
    		if(tmp != num) set.insert(tmp);
    	}
    	ll res = -1;
    	for(auto& x : set) {
            // cout<<x<<" : "<<getAbs(x - num);
    		if(res == -1) res = x;
    		else if(getAbs(x - num) < getAbs(res - num)) res = x;
    		else if(getAbs(x - num) == getAbs(res - num) && x < res) res = x;
            // cout<<" res : "<<res<<endl;
    	}
    	return to_string(res);
    }

    ll getAbs(ll a) {
    	if(a < 0) return -a;
    	return a;
    }

    ll getNum(ll k, bool isEven) {
    	string s = to_string(k);
    	int n = s.size(), idx = isEven ? n-1 : n-2;
    	while(idx >= 0) {
    		s += s[idx--];
    	}
    	return stoll(s);
    }
};