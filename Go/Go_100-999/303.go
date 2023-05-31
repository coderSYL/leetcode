// Go
// leetcode 303
// https://leetcode.cn/problems/range-sum-query-immutable/

type NumArray struct {
	sum []int
}

func Constructor(nums []int) NumArray {
	n := len(nums)
	sum := make([]int, n+1)
	for i, x := range nums {
		sum[i+1] = sum[i] + x
	}
	return NumArray{sum}
}

func (this *NumArray) SumRange(left int, right int) int {
	arr := this.sum
	return arr[right+1] - arr[left]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(left,right);
 */