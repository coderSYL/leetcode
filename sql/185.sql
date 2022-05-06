# MySQL
# leetcode 185
# https://leetcode-cn.com/problems/department-top-three-salaries/

SELECT DISTINCT
	d.name AS Department,
	e.name AS Employee,
	e.salary AS Salary
FROM Employee e, department d, 
	(
		SELECT
			departmentId,
			salary,
			dense_rank() over(PARTITION BY departmentId ORDER BY salary DESC) AS 'rank'
		FROM Employee
	) tmp
WHERE tmp.rank <= 3
	AND tmp.departmentId = d.id
	AND e.salary = tmp.salary
	AND tmp.departmentId = e.departmentId;