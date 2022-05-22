# MySQL
# leetcode 1355
# https://leetcode.cn/problems/activity-participants/

SELECT
    activity
FROM friends
GROUP BY activity
HAVING COUNT(*) > (SELECT COUNT(*) AS cnt FROM friends GROUP BY activity ORDER BY cnt ASC LIMIT 1)
    AND COUNT(*) < (SELECT COUNT(*) AS cnt FROM friends GROUP BY activity ORDER BY cnt DESC LIMIT 1);