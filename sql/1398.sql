# MySQL
# leetcode 1398
# https://leetcode.cn/problems/customers-who-bought-products-a-and-b-but-not-c/

SELECT c.*
FROM customers c
JOIN (
    SELECT
        customer_id,
        IF(product_name = 'A', 10000, 0) + IF(product_name = 'B', 100, 0) + IF(product_name = 'C', 1, 0) AS pts
    FROM orders
) t USING (customer_id)
GROUP BY c.customer_id
HAVING SUM(pts) >= 10100 AND SUM(pts) % 100 = 0;