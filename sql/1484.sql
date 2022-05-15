# MySQL
# leetcode 1484
# https://leetcode.cn/problems/group-sold-products-by-the-date/

SELECT
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product) AS products
FROM activities
GROUP BY sell_date
ORDER BY sell_date;