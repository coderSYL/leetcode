# MySQL
# leetcode 181
# https://leetcode-cn.com/problems/employees-earning-more-than-their-managers/

SELECT e.name AS Employee
FROM Employee e
JOIN Employee m
	ON e.managerID = m.id
WHERE e.salary > m.salary;