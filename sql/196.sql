# MySQL
# leetcode 196
# https://leetcode-cn.com/problems/delete-duplicate-emails/

DELETE FROM Person
WHERE id NOT IN (
    SELECT id
    FROM (
        SELECT MIN(id) as id
        FROM Person
        GROUP BY Email
    ) tmp
);