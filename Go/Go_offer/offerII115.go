// Go
// leetcode offerII 115
// https://leetcode.cn/problems/ur2n8P/

type Map struct {
	He, Ne, E, In []int
	Idx           int
}

func Constructor() Map {
	n := 10009
	he := make([]int, n)
	for i := 0; i < n; i++ {
		he[i] = -1
	}
	return Map{he, make([]int, n), make([]int, n), make([]int, n), 0}
}

func (m *Map) add(a, b int) {
	m.E[m.Idx] = b
	m.Ne[m.Idx] = m.He[a]
	m.He[a] = m.Idx
	m.Idx++
	m.In[b]++
}

func sequenceReconstruction(nums []int, sequences [][]int) bool {
	n := len(nums)
	m := Constructor()
	for i := 0; i < len(sequences); i++ {
		for j := 1; j < len(sequences[i]); j++ {
			m.add(sequences[i][j-1], sequences[i][j])
		}
	}

	q := make([]int, 0, 2)
	for i := 1; i <= n; i++ {
		if m.In[i] == 0 {
			q = append(q, i)
		}
	}

	loc := 0
	for len(q) != 0 {
		// fmt.Println("start loop size", len(q))
		if len(q) != 1 {
			return false
		}

		t := q[0]
		// fmt.Println(t)
		if nums[loc] != t {
			return false
		}
		loc++

		for i := m.He[t]; i != -1; i = m.Ne[i] {
			j := m.E[i]
			// fmt.Println("edge",j)
			m.In[j]--
			if m.In[j] == 0 {
				q = append(q, j)
			}
		}
		q = q[1:]
		// fmt.Println("end loop size", len(q))
	}
	return true
}