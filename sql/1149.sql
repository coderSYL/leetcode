# MySQL
# leetcode 1149
# https://leetcode.cn/problems/article-views-ii/

SELECT DISTINCT viewer_id AS id
FROM views
GROUP BY viewer_id, view_date
HAVING COUNT(DISTINCT article_id) >= 2;