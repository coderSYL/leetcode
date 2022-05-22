# MySQL
# leetcode 1369
# https://leetcode.cn/problems/get-the-second-most-recent-activity/

SELECT
    t.username,
    t.activity,
    t.startDate,
    t.endDate
FROM (
    SELECT *, ROW_NUMBER() OVER (PARTITION BY username ORDER BY startDate DESC) AS rk
    FROM useractivity
) t
WHERE rk = 2
UNION
SELECT
    t.username,
    t.activity,
    t.startDate,
    t.endDate
FROM (
    SELECT *, ROW_NUMBER() OVER (PARTITION BY username ORDER BY startDate DESC) AS rk
    FROM useractivity
) t
GROUP BY username
HAVING MAX(rk) = 1;