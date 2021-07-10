// C++
// leetcode 981
// https://leetcode-cn.com/problems/time-based-key-value-store/
// 使用了 lower_bound()

class TimeMap {
public:
    /** Initialize your data structure here. */
    map<string, map<int, string> >  ok;

    TimeMap() {
        ok.clear();
    }
    
    void set(string key, string value, int timestamp) {
        if(ok.find(key) == ok.end())
            ok[key] = map<int, string>{};
        ok[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // key 下无任何数据
        if(ok.find(key) == ok.end())
            return "";
        // 有timestamp
        auto it = ok[key].lower_bound(timestamp);

        if(it == ok[key].end())
            --it;


        if(it->first > timestamp ) {
            if(it == ok[key].begin())
                return "";
            --it;
        }
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */