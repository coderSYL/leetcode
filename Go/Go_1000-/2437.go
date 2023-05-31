// Go
// leetcode 2437
// https://leetcode.cn/problems/number-of-valid-clock-times/

func countTime(time string) int {
	hh, mm := 1, 1
	if time[0] == '?' {
		if time[1] == '?' {
			hh = 24
		} else if time[1] <= '3' {
			hh = 3
		} else {
			hh = 2
		}
	} else if time[1] == '?' {
		if time[0] == '2' {
			hh = 4
		} else {
			hh = 10
		}
	}

	if time[3] == '?' {
		if time[4] == '?' {
			mm = 60
		} else {
			mm = 6
		}
	} else if time[4] == '?' {
		mm = 10
	}

	return hh * mm
}