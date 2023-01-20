// C++
// leetcode 658
// https://leetcode.cn/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    	int n = arr.size(), l = 0, r = n - 1;

    	// 二分法找接近x的数
    	while(l <= r) {
    		int mid = (l + r) >> 1;
    		if (arr[mid] == x) {
    			r = mid;
    			break;
    		} else if (arr[mid] > x) {
    			r = mid - 1;
    		} else {
    			l = mid + 1;
    		}
    	}

    	// 找到x的最近数
    	if (r == -1) {
    		l = -1; r = 1;
    	} else if (r == n - 1) {
    		l = n - 2; r = n;
    	} else {
    		if(abs(arr[r] - x) <= abs(arr[r + 1] - x)) {
    			l = r - 1;
    			++r;
    		} else {
    			l = r;
    			r = r + 2;
    		}
    	}

    	// 以某数为中心开始扩散至k个
    	while (r - l - 1 < k) {
    		if (r == n) {
    			l--;
    		} else if (l == -1) {
    			r++;
    		} else {
    			if (abs(arr[l] - x) <= abs(arr[r] - x))
    				l--;
    			else
    				r++;
    		}
    	}

    	vector<int> res(k);
    	for (int i = l + 1; i < r; i++) {
    		res[i - l - 1] = arr[i];
    	}
    	return res;
    }
};