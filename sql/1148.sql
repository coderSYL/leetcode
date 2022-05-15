# MySQL
# leetcode 1148
# https://leetcode.cn/problems/article-views-i/

SELECT DISTINCT author_id AS id
FROM views 
WHERE author_id = viewer_id
ORDER BY author_id;