# MySQL
# leetcode 1077
# https://leetcode-cn.com/problems/project-employees-iii/

SELECT project_id, employee_id
FROM project p
LEFT JOIN employee e USING (employee_id)
LEFT JOIN(
    SELECT
        project_id,
        MAX(experience_years) AS max_year
    FROM project p 
    JOIN employee e USING (employee_id)
    GROUP BY project_id) t
    USING (project_id)
WHERE e.experience_years = t.max_year;