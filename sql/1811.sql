# MySQL
# leetcode 1811
# https://leetcode.cn/problems/find-interview-candidates/

SELECT DISTINCT u.name, u.mail
FROM (
    SELECT user_id
    FROM (
        SELECT
            u.user_id,
            c.contest_id - ROW_NUMBER() OVER (PARTITION BY u.user_id ORDER BY c.contest_id) AS what
        FROM users u 
        JOIN contests c 
            ON c.gold_medal = u.user_id
                OR c.silver_medal = u.user_id
                OR c.bronze_medal = u.user_id
    ) t
    GROUP BY user_id, what
    HAVING COUNT(*) >= 3
    UNION
    SELECT
        u.user_id
    FROM users u
    JOIN contests c ON c.gold_medal = u.user_id
    GROUP BY u.user_id
    HAVING COUNT(c.gold_medal) >= 3
) t1
LEFT JOIN users u USING (user_id)