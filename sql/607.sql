# MySQL
# leetcode 607
# https://leetcode-cn.com/problems/sales-person/

SELECT name
FROM salesPerson
WHERE sales_id NOT IN ( # 与red公司有关的销售的id
	SELECT DISTINCT sales_id
	FROM orders
	LEFT JOIN company c
		USING (com_id)
	WHERE c.name = 'RED' # RED 公司的 id
);