// Go
// leetcode 593
// https://leetcode.cn/problems/valid-square/

type Cnt struct{
	Min, c1, Max, c2 int
}

func getCnt() Cnt {
	return Cnt{1000_000_000, 0, -1000_000_000, 0}
}

func (t *Cnt)insert(v int) {
	if v < t.Min {
		t.Min = v
		t.c1 = 1
	} else if v == t.Min {
		t.c1++
	}

	if v > t.Max {
		t.Max = v
		t.c2 = 1
	} else if t.Max == v {
		t.c2++
	}
}

func (t *Cnt) check() bool {
	if t.Min * 2 != t.Max {
		return false
	}

	if t.c1 != 4 {
		return false
	}

	if t.c2 != 2 {
		return false
	}

	return true
}

func getD2(p1, p2 []int) int {
	dx, dy := p1[0] - p2[0], p1[1] - p2[1]
	return dx * dx + dy * dy
}

func validSquare(p1 []int, p2 []int, p3 []int, p4 []int) bool {
	cnt := getCnt()
	
	cnt.insert(getD2(p1, p2))
	cnt.insert(getD2(p1, p3))
	cnt.insert(getD2(p1, p4))
	cnt.insert(getD2(p3, p2))
	cnt.insert(getD2(p4, p2))
	cnt.insert(getD2(p3, p4))

	return cnt.check()
}