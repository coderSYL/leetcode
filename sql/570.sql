# MySQL
# leetcode 570
# https://leetcode-cn.com/problems/managers-with-at-least-5-direct-reports/

SELECT e.name
FROM Employee e
JOIN (
		SELECT 
			managerId,
			COUNT(managerId) AS cnt
		FROM Employee
		GROUP BY managerId
	) AS new_table
	ON e.id = new_table.managerId
WHERE new_table.cnt >= 5;