// Go
// leetcode 735
// https://leetcode.cn/problems/asteroid-collision/

func asteroidCollision(asteroids []int) []int {
	n, p, top := len(asteroids), 1, 0
	for p < n {
		// 栈空
		if top == -1 {
			top++
			asteroids[top] = asteroids[p]
			p++
			continue
		}

		// 会撞
		if asteroids[top] > 0 && asteroids[p] < 0 {
			if asteroids[top] + asteroids[p] < 0 {	// 右边大，左边碎
				top--
			} else if asteroids[top] + asteroids[p] == 0 {	// 一起碎
				top--
				p++
			} else {	// 栈顶大，右边碎
				p++
			}
		} else {
			// 不会撞
			top++
			asteroids[top] = asteroids[p]
			p++
		}
	}
	return asteroids[0 : top + 1]
}