// Go
// leetcode 729
// https://leetcode.cn/problems/my-calendar-i/

type Node struct {
    Ls, Rs *Node
    Add, Val int
}

const N = 1_000_000_000

func (p *Node) pushdown(len int) {
    if p.Ls == nil {
        p.Ls = &Node{nil, nil, 0, 0}
    }
    if p.Rs == nil {
        p.Rs = &Node{nil, nil, 0, 0}
    }

    if p.Add == 0 {
        return
    }
    x := p.Add
    p.Ls.Add += x
    p.Rs.Add += x
    p.Ls.Val += (len - len / 2) * x
    p.Rs.Val += len / 2 * x
    p.Add = 0
}

func (p *Node) pushup() {
    p.Val = p.Ls.Val + p.Rs.Val
}

func (p *Node) update(lc, rc, l, r, v int) {
    // 此 Node 的范围完全在
    if l <= lc && rc <= r {
        p.Val += v * (rc - lc + 1)
        p.Add += v
        return
    }

    p.pushdown(rc - lc + 1)
    mid := (lc + rc) >> 1

    if l <= mid {
        p.Ls.update(lc, mid, l, r, v)
    }
    if r > mid {
        p.Rs.update(mid + 1, rc, l, r, v)
    }
    p.pushup()
}

func (p *Node) query(lc, rc, l, r int) int {
    if l <= lc && rc <= r {
        return p.Val
    }
    p.pushdown(rc - lc + 1)
    mid, res := (lc + rc) >> 1, 0
    if l <= mid {
        res = p.Ls.query(lc, mid, l, r)
    }
    if r > mid {
        res += p.Rs.query(mid + 1, rc, l, r)
    }
    return res
}

type MyCalendar struct {
    Root *Node
}


func Constructor() MyCalendar {
    return MyCalendar{&Node{}}
}


func (this *MyCalendar) Book(start int, end int) bool {
    // x := this.Root.query(0, N + 1, start, end - 1)
    // fmt.Println(x)
    if this.Root.query(0, N + 1, start, end - 1) > 0 {
        return false
    }

    this.Root.update(0, N + 1, start, end - 1, 1)
    return true
}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(start,end);
 */