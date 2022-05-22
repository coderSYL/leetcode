# MySQL
# leetcode 1308
# https://leetcode.cn/problems/running-total-for-different-genders/

SELECT
    gender,
    day,
    SUM(score_points) OVER (PARTITION BY gender ORDER BY day) AS total
FROM scores
ORDER BY gender ASC, day ASC;