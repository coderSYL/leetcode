// Go
// leetcode 2446
// https://leetcode.cn/problems/determine-if-two-events-have-conflict/

import (
	"strconv"
)

func haveConflict(event1 []string, event2 []string) bool {
	start1, end1 := getIntTime(event1[0]), getIntTime(event1[1])
	start2, end2 := getIntTime(event2[0]), getIntTime(event2[1])
	return (start1 <= end2 && start1 >= start2) || (start2 <= end1 && start2 >= start1)
}

func getIntTime(s string) int { // "HH:MM"
	hour, _ := strconv.Atoi(s[0:2])
	min, _ := strconv.Atoi(s[3:])
	return hour*60 + min
}