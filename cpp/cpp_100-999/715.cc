// C++
// leetcode 715
// https://leetcode.cn/problems/range-module/

class RangeModule {
public:
	int start = 0, end = (int)1e9 + 10;
	const int ls = 0, rs = 1, add = 2, sum = 3;
	int tr[500010][4], cnt = 1;

	void pushup(int u) {
		tr[u][sum] = tr[tr[u][ls]][sum] + tr[tr[u][rs]][sum];
	}

	void pushdown(int u, int len) {
		if(tr[u][ls] == 0) {
			tr[u][ls] = ++cnt;
		}
		if(tr[u][rs] == 0) {
			tr[u][rs] = ++cnt;
		}
		if(tr[u][add] == 0)
			return;
		int a = tr[u][add];
		if(a == -1) {
			tr[tr[u][ls]][sum] = 0;
			tr[tr[u][rs]][sum] = 0;
		} else {
			tr[tr[u][ls]][sum] = len - len / 2;
			tr[tr[u][rs]][sum] = len / 2;
		}
		tr[tr[u][ls]][add] = a;
		tr[tr[u][rs]][add] = a;
		tr[u][add] = 0;
	}
	
	// [lc, rc) [l, r)
	void update(int u, int lc, int rc, int l, int r, int v) {
		// print info
		// cout<<"updating ["<<lc<<" : "<<rc<<"]"<<" ("<<l<<" : "<<r<<")"<<endl;

		int len = rc - lc + 1;
		if(l <= lc && rc <= r) {
			tr[u][sum] = (v == 1 ? len : 0);
			tr[u][add] = v;
			return;
		}
		if(len == 1)
			return;
		pushdown(u, len);

		int mid = (lc + rc) >> 1;
		if(l <= mid)
			update(tr[u][ls], lc, mid, l, r, v);
		if(r > mid)
			update(tr[u][rs], mid + 1, rc, l, r, v);
		pushup(u);
	}

	int query(int u, int lc, int rc, int l, int r) {
		if (l <= lc && rc <= r)
			return tr[u][sum];
		pushdown(u, rc - lc + 1);
		int mid = (lc + rc) >> 1, res = 0;
		if (l <= mid)
			res = query(tr[u][ls], lc, mid, l, r);
	    if (r > mid)
	    	res += query(tr[u][rs], mid + 1, rc, l, r);
	    return res;
	}

    RangeModule() {
    	memset(tr, 0, sizeof(tr));
    }
    
    void addRange(int left, int right) {
    	update(1, start, end, left, right-1, 1);
    }
    
    bool queryRange(int left, int right) {
    	
    	return query(1, start, end, left, right-1) == right - left;
    }
    
    void removeRange(int left, int right) {
    	update(1, start, end, left, right-1, -1);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */