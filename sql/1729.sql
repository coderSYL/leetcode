# MySQL
# leetcode 1729
# https://leetcode.cn/problems/find-followers-count/

SELECT user_id, COUNT(*) AS followers_count
FROM followers
GROUP BY user_id
ORDER BY user_id;