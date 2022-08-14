// Go
// leetcode 414
// https://leetcode-cn.com/problems/third-maximum-number/

func thirdMax(nums []int) int {
	sort.Ints(nums)
	cur, rk := nums[len(nums) - 1], 1
	for i := len(nums) - 2; i >= 0; i-- {
		if nums[i] < cur {
			rk++
			if rk == 3 {
				return nums[i]
			}
			cur = nums[i]
		}
	}
	return nums[len(nums) - 1]
}


// // 方法二
// type tri struct {
// 	arr []int
// 	filled []bool
// }

// func newTri() *tri {
// 	return &tri{make([]int, 3), make([]bool, 3)}
// }
// func (t tri) len() int {
//     res := 0
//     for  ; res < 3; res++ {
//         if !t.filled[res] {
//             return res
//         }
//     }
//     return res
// }

// func (t tri) push(x int) {
// 	i := 0
// 	for ; i < 3; i++ {
// 		if t.filled[i] {
// 			if t.arr[i] == x {
// 				return
// 			}
// 		} else {
// 			break
// 		}
// 	}

// 	switch i {
// 	case 0:
// 		t.arr[i] = x
// 		t.filled[i] = true
// 	case 1:
// 		t.arr[i] = x
// 		t.filled[i] = true
// 		if t.arr[1] > t.arr[0] {
// 			t.arr[0], t.arr[1] = t.arr[1], t.arr[0]
// 		}
// 	case 2:
// 		t.arr[i] = x
// 		t.filled[i] = true
// 		sort.Sort(sort.Reverse(sort.IntSlice(t.arr)))
// 	case 3:
// 		if t.arr[2] < x {
// 			t.arr[2] = x
// 			sort.Sort(sort.Reverse(sort.IntSlice(t.arr)))
// 		}
// 	}
// }

// func (t tri) get() int {
// 	if t.filled[2] {
// 		return t.arr[2]
// 	}
// 	return t.arr[0]
// }

// func thirdMax(nums []int) int {
// 	t := newTri()
// 	for _, x := range nums {
// 		t.push(x)
// 	}
//     // fmt.Println(t.len())
// 	return t.get()
// }