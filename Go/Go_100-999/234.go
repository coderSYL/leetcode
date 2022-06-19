// Go
// leetcode 234
// https://leetcode.cn/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(he *ListNode) bool {
	arr := make([]int,0,100)
	for he != nil {
		arr = append(arr, he.Val)
		he = he.Next
	}
	l, r := 0, len(arr) - 1
	for l < r {
		if arr[l] != arr[r] {
			return false
		}
		l++
		r--
	}
	return true
}