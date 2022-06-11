// Go
// leetcode 478
// https://leetcode.cn/problems/generate-random-point-in-a-circle/

type Solution struct {
    x, y, r float64
}


func Constructor(radius float64, x_center float64, y_center float64) Solution {
    return Solution{x_center, y_center, radius}
}


func (this *Solution) RandPoint() []float64 {
    rr := rand.Float64() * this.r
    angle := rand.Float64() * this.r
    if angle > rr {
        rr = this.r - rr
        angle = (rr + angle - this.r) / rr * 2 * math.Pi
    } else {
        angle = angle / rr * 2 * math.Pi
    }
    return []float64{this.x + math.Cos(angle) * rr, this.y + math.Sin(angle) * rr}
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(radius, x_center, y_center);
 * param_1 := obj.RandPoint();
 */