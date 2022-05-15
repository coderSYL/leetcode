# MySQL
# leetcode 1158
# https://leetcode.cn/problems/market-analysis-i/

SELECT
    u.user_id AS buyer_id,
    u.join_date,
    IFNULL(o.orders_in_2019, 0) AS orders_in_2019
FROM users AS u
LEFT JOIN (
    SELECT buyer_id, COUNT(*) AS orders_in_2019
    FROM orders
    WHERE YEAR(order_date) = '2019'
    GROUP BY buyer_id) AS o
    ON u.user_id = o.buyer_id;