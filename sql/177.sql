# MySQL
# leetcode 177
# https://leetcode-cn.com/problems/nth-highest-salary/

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;
    RETURN (
      # Write your MySQL query statement below.
      	SELECT IFNULL(( 
			SELECT DISTINCT salary 
			FROM Employee
			ORDER BY salary DESC
			LIMIT N,1),
				NULL)
    );
END