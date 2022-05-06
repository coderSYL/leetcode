# MySQL
# leetcode 176
# https://leetcode-cn.com/problems/second-highest-salary/

SELECT IFNULL(( 
	SELECT DISTINCT salary 
	FROM Employee
	ORDER BY salary DESC
	LIMIT 1,1),
	 NULL) AS SecondHighestSalary;