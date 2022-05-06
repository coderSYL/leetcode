# MySQL
# leetcode 579
# https://leetcode-cn.com/problems/find-cumulative-salary-of-an-employee/

SELECT
	Id,
	Month,
	SUM(Salary) OVER(PARTITION BY Id ORDER BY Month range 2 preceding) AS Salary
FROM (
	SELECT Id,Month,Salary
		FROM(
				SELECT Id,Month,Salary
    				,row_number () over (PARTITION by Id ORDER BY Month DESC) AS rk 
				FROM Employee
			) t1
	WHERE t1.rk >=2) t2
ORDER BY Id, Month DESC;