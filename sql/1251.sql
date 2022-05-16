# MySQL
# leetcode 1251
# https://leetcode.cn/problems/average-selling-price/

SELECT
    u.product_id,
    ROUND(SUM(u.units * p.price) / SUM(u.units), 2) AS average_price
FROM unitssold u
LEFT JOIN prices p
    ON u.product_id = p.product_id
        AND u.purchase_date BETWEEN start_date AND end_date
GROUP BY u.product_id;