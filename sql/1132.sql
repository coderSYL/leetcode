# MySQL
# leetcode 1132
# https://leetcode.cn/problems/reported-posts-ii/

SELECT ROUND(AVG(t.rate_per_day) * 100, 2) AS average_daily_percent
FROM (
    SELECT COUNT(DISTINCT r.post_id) / COUNT(DISTINCT a.post_id) AS rate_per_day
    FROM actions a 
    LEFT JOIN removals r
        USING (post_id)
    WHERE a.extra = 'spam'
    GROUP BY action_date
) AS t;