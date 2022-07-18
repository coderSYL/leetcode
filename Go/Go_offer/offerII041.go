// Go
// leetcode offerII 041
// https://leetcode.cn/problems/qIsx9U/

type MovingAverage struct {
	Arr []int
	P, Sum, Size int
}


/** Initialize your data structure here. */
func Constructor(size int) MovingAverage {
	return MovingAverage{make([]int, size), 0, 0, 0}
}


func (this *MovingAverage) Next(val int) float64 {
	bigSize := len(this.Arr)

	// 此次之前是否满了
	if this.Size < bigSize {
		// 未满，加值
		this.Size++
		this.Arr[this.P] = val
		this.P++
		this.Sum += val
	} else {
		// 满了，替换值
		this.P %= bigSize
		this.Sum += val - this.Arr[this.P]
		this.Arr[this.P] = val
		this.P++
	}
	
	return float64(this.Sum) / float64(this.Size)
}


/**
 * Your MovingAverage object will be instantiated and called as such:
 * obj := Constructor(size);
 * param_1 := obj.Next(val);
 */