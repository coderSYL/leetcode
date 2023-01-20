// C++
// leetcode 1652
// https://leetcode.cn/problems/defuse-the-bomb/

class Solution {
public:
	// 得到前缀和数组 arr 的原数组的 index 从 x 开始的 k 个数字的和
	// 超过边界则从头开始 
	int get(vector<int>& arr, int x, int k) {
		int n = arr.size() - 1;
		x = (x + 2 * n) % n;
		// cout<<">> GET from "<<x<<" following "<<k<<endl;
		if (x <= n - k) {
			// 可以弄完
			return arr[x + k] - arr[x];
		}

		int back = n - x, front = k - back;
		return get(arr, x, back) + get(arr, 0, front);
	}

    vector<int> decrypt(vector<int>& code, int k) {
    	int n = code.size();
    	vector<int> res(n, 0);
    	if (k == 0)
    		return res;
    	vector<int> sum(n + 1);
    	sum[0] = 0;
    	for (int i = 0; i < n; i++) {
    		sum[i + 1] = sum[i] + code[i];
    	}
        // cout<<"sum done"<<endl;
    	int diff;
    	if (k > 0) {
    		diff = 1;
    	} else {
    		diff = k;
    		k = -k;
    	}
    	for (int i = 0; i < n; i++) {
            // cout<<i<<endl;
    		res[i] = get(sum, i + diff, k);
            // cout<<"DONE"<<endl;
    	}
    	return res;
    }
};