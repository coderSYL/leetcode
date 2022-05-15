# MySQL
# leetcode 1164
# https://leetcode.cn/problems/product-price-at-a-given-date/

SELECT t.product_id, IFNULL(p.new_price, 10) AS price
FROM (
    SELECT product_id, MAX(IF(change_date <= "2019-08-16", change_date, NULL)) AS last
    FROM products
    GROUP BY product_id
) t 
LEFT JOIN products p 
	ON p.product_id = t.product_id
    AND p.change_date = t.last;