# MySQL
# leetcode 1285
# https://leetcode.cn/problems/find-the-start-and-end-number-of-continuous-ranges/

SELECT
    MIN(log_id) AS start_id,
    MAX(log_id) AS end_id
FROM(
    SELECT log_id, log_id - ROW_NUMBER() OVER (ORDER BY log_id)AS rk
    FROM logs
) t
GROUP BY rk;