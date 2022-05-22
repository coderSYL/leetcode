# MySQL
# leetcode 1270
# https://leetcode.cn/problems/all-people-report-to-the-given-manager/

SELECT employee_id
FROM employees 
WHERE manager_id IN (
    SELECT employee_id
    FROM employees 
    WHERE manager_id IN (SELECT employee_id FROM employees WHERE manager_id = 1)
) AND employee_id != 1;