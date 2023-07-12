// Go
// leetcode 1483
// https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/

type TreeAncestor struct {
	f [][]int
}

func Constructor(n int, parent []int) TreeAncestor {
	f := make([][]int, n)
	level := 0
	for i := 1; i <= n; i *= 2 {
		level++
	}
	model := make([]int, level)
	for i := 1; i < level; i++ {
		model[i] = -1
	}
	// fmt.Println(model)
	for i := 0; i < n; i++ {
		f[i] = make([]int, level)

		copy(f[i], model)
		f[i][0] = parent[i]
		// fmt.Println(f[i])
	}
	for j := 1; j < level; j++ {
		for i := 0; i < n; i++ {
			a := f[i][j-1]
			if a == -1 {
				continue
			}
			f[i][j] = f[a][j-1]
		}
	}
	return TreeAncestor{f}
}

func (this *TreeAncestor) GetKthAncestor(node int, k int) int {
	for i := 16; i >= 0; i-- {
		if (k>>i)&1 == 1 {
			node = this.f[node][i]
		}
		if node == -1 {
			break
		}
	}
	return node
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * obj := Constructor(n, parent);
 * param_1 := obj.GetKthAncestor(node,k);
 */