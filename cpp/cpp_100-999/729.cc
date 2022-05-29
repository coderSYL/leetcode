// C++
// leetcode 729
// https://leetcode.cn/problems/my-calendar-i/
// 线段树

class MyCalendar {
public:
	int N = (int)1e9;
	int ls = 0, rs = 1, add = 2, val = 3, cnt = 1;
	int tr[120010][4];

	// 更新 tr[u][val]
	void pushup(int u) {
		tr[u][val] = tr[tr[u][ls]][val] + tr[tr[u][rs]][val];
	}

	// 把 tr[u] 的 add 对两个子树进行下传
	void pushdown(int u, int len) {
		int cur_add = tr[u][add];
		if(cur_add == 0) return;
		int l_son = tr[u][ls], r_son = tr[u][rs];
		tr[l_son][add] += cur_add;
		tr[r_son][add] += cur_add;
		tr[l_son][val] += (len+1)/2 * cur_add;
		tr[r_son][val] += len/2 * cur_add;
		tr[u][add] = 0;
	}

	void update(int u, int lc, int rc, int l, int r, int v) {
		if(u == 0)
			cout<<"error"<<endl;
		if(l <= lc && rc <= r) {
			tr[u][val] += (rc - lc + 1) * v;
			tr[u][add] += v;
			return;
		}
		lazyCreate(u);
		pushdown(u, rc-lc+1);
		int mid = (lc + rc) >> 1;
		if(l <= mid) update(tr[u][ls], lc, mid, l, r, v);
		if (r > mid) update(tr[u][rs], mid + 1, rc, l, r, v);
		pushup(u);
	}

	int query(int u, int lc, int rc, int l, int r) {
		// 如果此节点代表的范围在 [l, r] 中，直接返回val
		if (l <= lc && rc <= r) return tr[u][val];
		// 不在的话就造两个子节点
		lazyCreate(u);
		// 把当前节点下传
		pushdown(u, rc - lc + 1);
		int mid = (lc + rc) >> 1, ans = 0;
        if (l <= mid)
        	ans = query(tr[u][ls], lc, mid, l, r);
        if (r > mid) ans += query(tr[u][rs], mid + 1, rc, l, r);
        return ans;
	}

	// 确保 tr[u]左右子树都有所指向
	void lazyCreate(int u) {
		if(tr[u][ls] == 0) {
			tr[u][ls] = ++cnt;
		}
		if(tr[u][rs] == 0) {
			tr[u][rs] = ++cnt;
		}
	}

    MyCalendar() {
    	memset(tr, 0, sizeof(tr));
    }
    
    bool book(int start, int end) {
        int tmp = query(1, 1, N + 1, start + 1, end);
        // cout<<tmp<<endl;
    	if(tmp > 0)
    		return false;
    	update(1, 1, N + 1, start + 1, end, 1);
    	return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */