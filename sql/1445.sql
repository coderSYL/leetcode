# MySQL
# leetcode 1445
# https://leetcode.cn/problems/apples-oranges/

SELECT
    sale_date,
    SUM(IF(fruit = 'apples', sold_num, -sold_num)) AS diff
FROM sales
GROUP BY sale_date;