# MySQL
# leetcode 1211
# https://leetcode.cn/problems/queries-quality-and-percentage/

SELECT
    query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(COUNT(IF(rating < 3, 1, NULL)) / COUNT(1) * 100, 2) AS poor_query_percentage
FROM queries
GROUP BY query_name;