# MySQL
# leetcode 182
# https://leetcode-cn.com/problems/duplicate-emails/

SELECT
    Email
FROM (
    SELECT
        Email,
        COUNT(Email) AS count
    FROM Person
    GROUP BY Email HAVING count > 1
) tmp;