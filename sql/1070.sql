# MySQL
# leetcode 1070
# https://leetcode-cn.com/problems/product-sales-analysis-iii/

SELECT
    product_id,
    s.year AS first_year,
    quantity,
    price
FROM(
	SELECT
	    product_id,
	    MIN(year) AS year
	FROM sales
	GROUP BY product_id
) t 
LEFT JOIN sales s
USING (product_id, year);