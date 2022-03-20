# MySQL
# leetcode 586
# https://leetcode-cn.com/problems/customer-placing-the-largest-number-of-orders/

SELECT
    customer_number
FROM(
    SELECT
        customer_number,
        COUNT(order_number) AS oo
    FROM Orders
    GROUP BY customer_number
    ORDER BY oo DESC
    LIMIT 0,1
) tmp;