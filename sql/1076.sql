# MySQL
# leetcode 1076
# https://leetcode-cn.com/problems/project-employees-ii/

SELECT
    project_id
FROM project
GROUP BY project_id
HAVING COUNT(*) >= (
    SELECT COUNT(*) FROM project GROUP BY project_id ORDER BY cnt DESC LIMIT 1
);