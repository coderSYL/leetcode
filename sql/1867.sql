# MySQL
# leetcode 1867
# https://leetcode.cn/problems/orders-with-maximum-quantity-above-average/

SELECT order_id
FROM ordersdetails
GROUP BY order_id
HAVING MAX(quantity) > (
	SELECT AVG(quantity) AS what 
	FROM ordersdetails 
	GROUP BY order_id 
	ORDER BY what DESC 
	LIMIT 1);