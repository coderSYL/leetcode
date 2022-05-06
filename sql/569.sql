# MySQL
# leetcode 569
# https://leetcode-cn.com/problems/median-employee-salary/

SELECT
	id,
	company,
	salary
FROM (
	    SELECT
	        *,
	        CAST(ROW_NUMBER() over(PARTITION BY COMPANY ORDER BY salary ASC, id ASC) AS signed) AS ok,
	        CAST(ROW_NUMBER() over(PARTITION BY COMPANY ORDER BY salary DESC, id DESC) AS signed) AS ok1
	    FROM Employee
	) AS new_table
WHERE ok = ok1
	OR abs(ok - ok1) = 1;
