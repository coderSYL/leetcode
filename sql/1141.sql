# MySQL
# leetcode 1141
# https://leetcode.cn/problems/user-activity-for-the-past-30-days-i/

SELECT
    activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users
FROM activity
WHERE activity_date > "2019-06-27"
GROUP BY activity_date;