# MySQL
# leetcode 1264
# https://leetcode.cn/problems/page-recommendations/

SELECT DISTINCT l.page_id AS recommended_page
FROM (
    SELECT IF(user1_id = 1, user2_id, user1_id) AS user_id
    FROM friendship
    WHERE user1_id = 1 OR user2_id = 1
) t1
LEFT JOIN likes l USING (user_id)
WHERE l.page_id NOT IN (SELECT page_id FROM likes WHERE user_id = 1)
    AND l.page_id IS NOT NULL;