// Go
// leetcode 2535
// https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array/

func differenceOfSum(nums []int) (res int) {
    for _, x := range nums {
        res += x - getNumSum(x)
    }
    return res
}

func getNumSum(a int) (res int) {
    for a > 0 {
        res += a%10
        a /= 10
    }
    return res
}s