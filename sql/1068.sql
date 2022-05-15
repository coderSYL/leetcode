# MySQL
# leetcode 1068
# https://leetcode-cn.com/problems/product-sales-analysis-i/

SELECT
    p.product_name,
    s.year,
    s.price
FROM sales s
LEFT JOIN product p
    USING (product_id);