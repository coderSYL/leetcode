# MySQL
# leetcode 1082
# https://leetcode.cn/problems/sales-analysis-i/

SELECT seller_id
FROM sales s
GROUP BY seller_id
HAVING SUM(price) >= (SELECT SUM(price) AS total_sale
    FROM sales s
    GROUP BY seller_id
    ORDER BY total_sale DESC
    LIMIT 1);