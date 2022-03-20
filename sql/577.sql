# MySQL
# leetcode 577
# https://leetcode-cn.com/problems/employee-bonus/

SELECT
    e.name,
    b.bonus
FROM Employee e
LEFT JOIN Bonus b USING (empId)
WHERE b.bonus < 1000 OR b.bonus IS NULL;