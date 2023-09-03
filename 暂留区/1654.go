// Go
// leetcode 1654
// https://leetcode.cn/problems/minimum-jumps-to-reach-home/

func minimumJumps(forbidden []int, a int, b int, home int) int {
	fmt.Println("---")
	bad := make(map[int]bool, len(forbidden))
	far := 0
	for _, x := range forbidden {
		bad[x] = true
		far = max(far, x)
	}
	
	far = max(far + a + b, home + b)

	isBad := func(x int) bool {
		_, ok := bad[x]
		return ok
	}

	q := []int{0}
	qCantBackwark := []int{}
	step := 0
	vis := make([]bool, far+1)
	vis[0] = true
	cnt := 0
	cntMax := far - len(forbidden) + 1


	deleteNFront := func(arr []int, x int) {
		n := len(arr)
		for i:=x; i<n; i++ {
			arr[i-x] = arr[i]
		}
		arr = arr[:n-x]
	}

	afterForward := func(x int) bool {
		if x > far || isBad(x) || vis[x] {
			return false
		}
		if x == home {
			return true
		}
		q = append(q, x)
		vis[x] = true
		cnt++
		return false
	}

	afterBackWard := func(x int) bool {
		if x <= 0 || isBad(x) || vis[x] {
			return false
		}
		if x == home {
			return true
		}
		qCantBackwark = append(qCantBackwark, x)
		vis[x] = true
		cnt++
		return false
	}

	for len(q) + len(qCantBackwark) > 0 && cnt < cntMax {
		sz1 := len(q)
		sz2 := len(qCantBackwark)
		fmt.Println(step, len(q),q[0], len(qCantBackwark))
		for i:=sz1-1; i >= 0; i-- {
			x := q[i]
			if x == home {
				return step
			}
			afterForward(x+a)
			afterBackWard(x-b)
		}
		deleteNFront(q, sz1)
		for i:=sz2-1; i>= 0; i-- {
			x := qCantBackwark[i]
			if x == home {
				return step
			}
			afterForward(x+a)
		}
		deleteNFront(qCantBackwark, sz2)
		step++
	}
	return -1
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}