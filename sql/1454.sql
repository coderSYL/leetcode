# MySQL
# leetcode 1454
# https://leetcode.cn/problems/active-users/

SELECT DISTINCT a.*
FROM accounts a 
JOIN (
    SELECT
        id,
        COUNT(*) AS cnt 
    FROM (
        SELECT DISTINCT
            id,
            login_date,
            SUBDATE(login_date , DENSE_RANK() OVER (PARTITION BY id ORDER BY login_date)) AS rk
        FROM logins
    ) t
    GROUP BY id,rk
) t2 USING (id)
WHERE t2.cnt >= 5
ORDER BY id;