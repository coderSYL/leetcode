// C++
// leetcode 2034
// https://leetcode-cn.com/problems/stock-price-fluctuation/

class StockPrice {
public:
	multiset<int> val;
	map<int, int> m;
	int currentTime = INT_MIN;
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
    	auto it = m.find(timestamp);
    	currentTime = max(currentTime, timestamp);
    	if(m.find(timestamp) == m.end()) {
    		// 不存在，直接插入
    		m[timestamp] = price;
    		val.insert(price);
    	} else {
    		// 存在，改值
    		auto rmv = val.find(it->second);
    		val.erase(rmv);
    		val.insert(price);
    		it->second = price;
    	}
    }
    
    int current() {
    	return m[currentTime];
    }
    
    int maximum() {
    	return *val.rbegin();
    }
    
    int minimum() {
    	return *val.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */