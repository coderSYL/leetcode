# MySQL
# leetcode 1393
# https://leetcode.cn/problems/capital-gainloss/

SELECT
	stock_name,
	SUM(CASE operation 
			WHEN 'Buy' THEN - price 
			WHEN 'Sell' THEN price 
		END) AS capital_gain_loss
FROM stocks
GROUP BY stock_name