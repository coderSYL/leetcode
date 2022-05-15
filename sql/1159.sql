# MySQL
# leetcode 1159
# https://leetcode.cn/problems/market-analysis-ii/

SELECT u.user_id AS seller_id, IFNULL(tmp.2nd_item_fav_brand, 'no') AS 2nd_item_fav_brand
FROM users u
LEFT JOIN (
	SELECT u.user_id, IF(u.favorite_brand = i.item_brand, 'yes', 'no') AS 2nd_item_fav_brand
	FROM (
	    SELECT
	        seller_id,
	        item_id,
	        ROW_NUMBER() OVER(PARTITION BY seller_id ORDER BY order_date) as rk
	    FROM orders
	    ORDER BY seller_id, order_date) AS o
	RIGHT JOIN users u ON o.seller_id = u.user_id
	JOIN items i USING(item_id)
	WHERE o.rk = 2
) AS tmp USING (user_id);