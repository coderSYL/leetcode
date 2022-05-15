# MySQL
# leetcode 1174
# https://leetcode.cn/problems/immediate-food-delivery-ii/

SELECT ROUND(COUNT(IF(order_date = customer_pref_delivery_date, 1, NULL)) * 100 / COUNT(t.order_date), 2) AS immediate_percentage
FROM (
    SELECT customer_id, MIN(order_date) AS order_date
    FROM delivery
    GROUP BY customer_id
) t
LEFT JOIN delivery d using(customer_id, order_date);