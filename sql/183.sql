# MySQL
# leetcode 183
# https://leetcode-cn.com/problems/customers-who-never-order/

SELECT
    c.Name AS Customers
FROM Customers c
LEFT JOIN (
		SELECT
		    CustomerId,
		    COUNT(CustomerId) AS cnt
		FROM Orders
		GROUP BY Id) tmp
	ON c.Id = tmp.CustomerId
WHERE cnt IS NULL;