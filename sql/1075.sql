# MySQL
# leetcode 1075
# https://leetcode-cn.com/problems/project-employees-i/

SELECT
    p.project_id,
    ROUND(AVG(e.experience_years), 2) AS average_years
FROM project p
LEFT JOIN employee e USING (employee_id)
GROUP BY project_id;