# MySQL
# leetcode 1532
# https://leetcode.cn/problems/the-most-recent-three-orders/

SELECT
    c.name AS customer_name,
    c.customer_id,
    o.order_id,
    o.order_date
FROM (
    SELECT *, ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date DESC) AS rk
    FROM orders
) o
JOIN customers c USING (customer_id)
WHERE rk <= 3
ORDER BY customer_name ASC, customer_id ASC, order_date DESC;