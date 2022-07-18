// C++
// leetcode offerII 041
// https://leetcode.cn/problems/qIsx9U/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    int size;
    vector<int> arr;
    int sum, p;
    MovingAverage(int size_) {
    	sum = 0;
    	size = 0;
    	arr.resize(size_);
    	p = 0;
    }
    
    double next(int val) {
    	if (size < arr.size()) {
    		size++;
    		sum += val;
    		arr[p] = val;
    		p = (p + 1) % arr.size();
    		double d_sum = (double)sum;
    		return d_sum / size;
    	} else {
    		sum += val - arr[p];
    		arr[p] = val;
    		p = (p + 1) % arr.size();
    		double d_sum = (double)sum;
    		return d_sum / size;
    	}
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */