// Go
// leetcode 445
// https://leetcode.cn/problems/add-two-numbers-ii/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	l1 = reverseList(l1)
	l2 = reverseList(l2)
	
	res := add(l1, l2, false)

	return reverseList(res)
}

func reverseList(l *ListNode) *ListNode {
	if l == nil {
		return nil
	}
	arr := []*ListNode{}
	for l != nil {
		arr = append(arr, l)
        l = l.Next
	}

	n:=len(arr)
	for i:=n-1; i>0; i-- {
		arr[i].Next = arr[i-1]
	}
	arr[0].Next = nil

	return arr[n-1]
}

func add(l1, l2 *ListNode, one bool) *ListNode {
	if !one {
		if l1 == nil && l2 == nil {
			return nil
		}
		if l1 == nil {
			return &ListNode{l2.Val, l2.Next}
		}
		if l2 == nil {
			return &ListNode{l1.Val, l1.Next}
		}
	}
	sum := 0
	if l1 != nil {
		sum += l1.Val
		l1 = l1.Next
	}
	if l2 != nil {
		sum += l2.Val
		l2 = l2.Next
	}
	if one {
		sum++
	}

	u := sum % 10
	nextOne := sum >= 10
	return &ListNode{u, add(l1, l2, nextOne)}
}

// // 方法二
// func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
// 	arr1 := getArr(l1)
// 	arr2 := getArr(l2)
// 	if len(arr1) < len(arr2) {
// 		arr1, arr2 = arr2, arr1
// 	}

// 	one := false
// 	n1, n2 := len(arr1), len(arr2)
// 	for i:=0; i<n1; i++ {
// 		if one {
// 			arr1[i]++
// 			one = false
// 		}
// 		if i < n2 {
// 			arr1[i] += arr2[i]
// 		}
// 		if arr1[i] >= 10 {
// 			one = true
// 			arr1[i] %= 10
// 		}
// 	}
//     if one {
//         arr1 = append(arr1, 1)
//     }

// 	return getListNode(arr1)
// }

// func getArr(ln *ListNode) (res []int) {
// 	for ln != nil {
// 		res = append(res, ln.Val)
// 		ln = ln.Next
// 	}
// 	left, right := 0, len(res)-1
// 	for left < right {
// 		res[left], res[right] = res[right], res[left]
// 		left++
// 		right--
// 	}
// 	return res
// }

// func getListNode(arr []int) *ListNode {
// 	n := len(arr)
// 	tmp := make([]*ListNode, n)
// 	tmp[0] = &ListNode{arr[0], nil}
// 	for i:=1; i<n; i++ {
// 		tmp[i] = &ListNode{arr[i], tmp[i-1]}
// 	}
// 	return tmp[n-1]
// }