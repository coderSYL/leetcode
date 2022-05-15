# MySQL
# leetcode 1965
# https://leetcode.cn/problems/employees-with-missing-information/

SELECT
    employee_id
FROM employees e
LEFT JOIN salaries s USING (employee_id)
WHERE s.salary IS NULL
UNION
SELECT
    employee_id
FROM employees e
RIGHT JOIN salaries s USING (employee_id)
WHERE e.name IS NULL
ORDER BY employee_id;