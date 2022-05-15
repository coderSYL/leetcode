# MySQL
# leetcode 1107
# https://leetcode.cn/problems/new-users-daily-count/

SELECT login_date, COUNT(*) AS user_count
FROM (
    SELECT
        user_id,
        MIN(activity_date) AS login_date
    FROM traffic
    WHERE activity = 'login'
    GROUP BY user_id
    HAVING login_date >= "2019-04-01") t
GROUP BY login_date;