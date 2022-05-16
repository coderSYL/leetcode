# MySQL
# leetcode 1241
# https://leetcode.cn/problems/number-of-comments-per-post/

SELECT
    p.post_id,
    IFNULL(COUNT(DISTINCT s.sub_id), 0) AS number_of_comments
FROM(
    SELECT DISTINCT sub_id AS post_id
    FROM submissions
    WHERE parent_id IS NULL
) p
LEFT JOIN submissions s
    ON p.post_id = s.parent_id
GROUP BY post_id
ORDER BY post_id;