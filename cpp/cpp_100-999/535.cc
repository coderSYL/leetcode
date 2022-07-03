// C++
// leetcode 535
// https://leetcode.cn/problems/encode-and-decode-tinyurl/

class Solution {
public:
	using ull = unsigned long long;
	const ull base = 11;
	const string code = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const ull len = code.size();
    unordered_map<string, string> m;

    ull stringToUll(string &s) {
    	ull res = 0;
    	for(auto c : s) {
    		res *= base;
    		res += c;
    	}
    	return res;
    }

    string ullToString(ull n) {
    	vector<char> tmp;
    	while(n != 0) {
    		tmp.push_back(code[n % len]);
    		n /= len;
    	}
    	return string(tmp.begin(), tmp.end());
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = ullToString(stringToUll(longUrl));
        m[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));



// // 三叶
// class Solution {
// public:
//     unordered_map<string, string> origin2Tiny;
//     unordered_map<string, string> tiny2Origin;
//     const string str = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     int len = str.size();
//     int k = 6;
//     string prefix = "wxy";
//     // Encodes a URL to a shortened URL.
//     string encode(string longUrl) {
//         while(origin2Tiny.find(longUrl) == origin2Tiny.end()) {
//             char cs[k];
//             for(int i = 0; i < k; i++) {
//                 cs[i] = str[rand()%len];
//             }
//             string cur = prefix + string(cs, cs+k);
//             if(tiny2Origin.find(cur) != tiny2Origin.end()) {
//                 continue;
//             }
//             tiny2Origin[cur] = longUrl;
//             origin2Tiny[longUrl] = cur;
//         }
//         return origin2Tiny[longUrl];
//     }

//     // Decodes a shortened URL to its original URL.
//     string decode(string shortUrl) {
//         return tiny2Origin[shortUrl];
//     }
// };