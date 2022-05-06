# MySQL
# leetcode 184
# https://leetcode-cn.com/problemset/database/

SELECT
	d.name AS Department,
	e.name AS Employee,
	e.salary AS salary
FROM Employee e
JOIN (
		SELECT 
			departmentId,
			MAX(salary) AS top_salary
		FROM Employee
		GROUP BY departmentId
	) t1
    USING (departmentId)
JOIN department d
	ON e.departmentId = d.id 
WHERE e.salary = t1.top_salary;