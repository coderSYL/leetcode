# MySQL
# leetcode 1142
# https://leetcode.cn/problems/user-activity-for-the-past-30-days-ii/

SELECT
    IFNULL(ROUND(COUNT(DISTINCT session_id) / COUNT(DISTINCT user_id), 2), 0.00) AS average_sessions_per_user
FROM activity
WHERE activity_date > "2019-06-27";