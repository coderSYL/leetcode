# MySQL
# leetcode 1173 
# https://leetcode.cn/problems/immediate-food-delivery-i/

SELECT ROUND(COUNT(IF(order_date = customer_pref_delivery_date,1,NULL)) / COUNT(*)  * 100, 2) AS immediate_percentage
FROM delivery;