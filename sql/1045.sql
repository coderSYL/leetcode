# MySQL
# leetcode 1045
# https://leetcode-cn.com/problems/customers-who-bought-all-products/

SELECT t1.customer_id
FROM (
	SELECT
		customer_id,
		COUNT(DISTINCT product_key) AS cnt
	FROM customer
    GROUP BY customer_id
) t1, (SELECT COUNT(DISTINCT product_key) AS product_num FROM product) AS t2 
WHERE t1.cnt = t2.product_num;
