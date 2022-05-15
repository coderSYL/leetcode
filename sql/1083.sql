# MySQL
# leetcode 1083
# https://leetcode.cn/problems/sales-analysis-ii/

SELECT DISTINCT buyer_id
FROM sales s
WHERE product_id = (SELECT product_id FROM product WHERE product_name = 'S8')
    AND buyer_id NOT IN (SELECT buyer_id
        FROM sales s
        WHERE product_id = (SELECT product_id FROM product WHERE product_name = 'iPhone'));
