# MySQL
# leetcode 1084
# https://leetcode.cn/problems/sales-analysis-iii/

SELECT product_id, product_name
FROM sales
LEFT JOIN product USING (product_id)
GROUP BY product_id
HAVING MIN(sale_date) >= "2019-01-01"
    AND  MAX(sale_date) <= "2019-03-31";