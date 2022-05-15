# MySQL
# leetcode 1667
# https://leetcode.cn/problems/fix-names-in-a-table/

SELECT  
    user_id,
    CONCAT(UCASE(LEFT(name, 1)), LCASE(SUBSTRING(name, 2))) AS name
FROM users
ORDER BY user_id;