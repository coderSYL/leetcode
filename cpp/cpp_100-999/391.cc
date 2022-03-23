// C++
// leetcode 391
// https://leetcode-cn.com/problems/perfect-rectangle/
// 思路偷三叶的

class Solution {
public:
	struct four	{
		int heng;
		int xia;
		int shang;
		bool isLeft;
		four(int heng, int xia, int shang, bool isLeft) : heng(heng), xia(xia), shang(shang), isLeft(isLeft) {}
		bool operator<(const four& a) const {
			if(heng != a.heng)
				return	heng < a.heng;
			return	xia < a.xia;
		}
	};


    bool isRectangleCover(vector<vector<int>>& rectangles) {
    	int n = rectangles.size();
    	vector<four>    rs;
    	// 数据录入
    	for (int i = 0; i < n; i++) {
    		vector<int>& rect = rectangles[i];
    		rs.push_back(four(rect[0], rect[1], rect[3], true));
    		rs.push_back(four(rect[2], rect[1], rect[3], false));
    	}
    	sort(rs.begin(), rs.end());
    	n *= 2;

    	vector<int>	l1, l2;
    	for(int l = 0; l < n; ) {
    		int r = l;
    		l1.clear();
    		l2.clear();
    		int hengForThis = rs[l].heng;
    		while(r < n && rs[r].heng == hengForThis)
    			r++;
    		// 横坐标相同的边的判断
    		for (int i = l; i < r; i++) {
    			auto &f = rs[i];
    			auto &ll = (f.isLeft ? l1 : l2);
    			if(ll.empty()) {
    				// 空的，直接塞
    				ll.push_back(f.xia);
    				ll.push_back(f.shang);
    			} else {
    				// 非空
    				if(ll.back() > f.xia)	// 重叠了
    					return	false;
    				else if(ll.back() == f.xia) {	// 续上了
    					ll.back() = f.shang;
    				} else {	// 没重叠，直接加
    					ll.push_back(f.xia);
    					ll.push_back(f.shang);
    				}
    			}
    		}

    		if(l > 0 && r < n) {
    			// 不是边缘
    			if(l1.size() != l2.size())
    				return	false;
    			for(int i = 0; i < l1.size(); i++)
    				if(l1[i] != l2[i])
    					return	false;
    		} else {
    			// 是边缘
    			if(l1.size() + l2.size() != 2)
    				return	false;
    		}
    		l = r;
    	}
    	return	true;
    }
};