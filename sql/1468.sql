# MySQL
# leetcode 1468
# https://leetcode.cn/problems/calculate-salaries/

SELECT
    company_id,
    employee_id,
    employee_name,
    CASE
        WHEN top < 1000 THEN salary
        WHEN top > 10000 THEN ROUND(0.51 * salary, 0)
        ELSE ROUND(0.76 * salary, 0)
    END AS salary
FROM salaries s
LEFT JOIN (
    SELECT
        company_id,
        MAX(salary) AS top
    FROM salaries
    GROUP BY company_id
) t using (company_id);