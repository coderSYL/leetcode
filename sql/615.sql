# MySQL
# leetcode 615
# https://leetcode-cn.com/problems/average-salary-departments-vs-company/

SELECT DISTINCT 
	LEFT(pay_date, 7) AS pay_month,
	e.department_id,
	CASE
		WHEN ROUND(SUM(amount) / COUNT(*), 4) = com_t.avg_company THEN "same"
		WHEN ROUND(SUM(amount) / COUNT(*), 4) < com_t.avg_company THEN "lower"
		ELSE "higher"
	END AS comparison
FROM salary s
JOIN Employee e
	USING (employee_id)
JOIN (	
	SELECT
		pay_date,
		ROUND(SUM(amount) / COUNT(*), 4) AS avg_company
	FROM salary
	GROUP BY pay_date
) AS com_t
	USING (pay_date)
GROUP BY e.department_id, pay_date;