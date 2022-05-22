# MySQL
# leetcode 1596
# https://leetcode.cn/problems/the-most-frequently-ordered-products-for-each-customer/

SELECT
    customer_id,
    product_id,
    p.product_name
FROM (
    SELECT
        customer_id,
        product_id,
        DENSE_RANK() OVER (PARTITION BY customer_id ORDER BY cnt DESC) AS rk
    FROM (
        SELECT
            customer_id,
            product_id,
            COUNT(*) AS cnt
        FROM orders
        GROUP BY customer_id, product_id
    ) t1
) t2 
LEFT JOIN products p USING (product_id)
WHERE t2.rk = 1;