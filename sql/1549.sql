# MySQL
# leetcode 1549
# https://leetcode.cn/problems/the-most-recent-orders-for-each-product/

SELECT
    p.product_name,
    p.product_id,
    o.order_id,
    t.good_date AS order_date
FROM orders o
JOIN (
    SELECT
        product_id,
        MAX(order_date) AS good_date
    FROM orders o
    GROUP BY product_id
) t USING (product_id)
JOIN products p
    USING (product_id)
WHERE o.order_date = t.good_date
ORDER BY product_name ASC, product_id ASC, order_id ASC;