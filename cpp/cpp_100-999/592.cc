// C++
// leetcode 592
// https://leetcode.cn/problems/fraction-addition-and-subtraction/

class Solution {
public:
	// 计算最大公约数
	int getGcd(int a, int b) {
		if (b > a) {
			swap(a, b);
		}
	    if(b == 0)  return a;
	    return getGcd(b, a % b);
	}

    string fractionAddition(string s) {
    	int arr[20];
    	bool isNegative = false;
    	int tmp = 0, size = 0;

    	// 数据统计
    	for (auto c : s) {
    		if (c == '/') {
    			if (isNegative) {
    				tmp = - tmp;
    				isNegative = false;
    			}
    			arr[size++] = tmp;
    			tmp = 0;
    		} else if (c == '+') {
    			if (isNegative) {
    				tmp = - tmp;
    				isNegative = false;
    			}
    			arr[size++] = tmp;
    			tmp = 0;
    		} else if (c == '-') {
    			if (isNegative) {
    				tmp = - tmp;
    			}
    			if (tmp != 0)
    				arr[size++] = tmp;
    			tmp = 0;
    			isNegative = true;
    		} else {
    			// 数字
    			tmp = 10 * tmp + (c - '0');
    		}
    	}
    	arr[size++] = tmp;

    	tmp = 2;
    	int a = arr[0], b = arr[1], c, d, down;

    	// 处理计算
    	while (tmp < size) {
    		c = arr[tmp++];
    		d = arr[tmp++];
    		down = getGcd(b, d);
    		down = (b / down) * d;
    		a = a * down / b;
    		c = c * down / d;
    		a += c;
    		b = down;
    		down = getGcd(a > 0 ? a : -a, b);
    		a /= down;
    		b /= down;
    	}

    	if (a == 0)
    		b = 1;
    	return to_string(a) + "/" + to_string(b);
    }
};