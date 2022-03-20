# MySQL
# leetcode 584
# https://leetcode-cn.com/problems/find-customer-referee/

SELECT name
FROM customer
WHERE referee_id IS NULL OR referee_id != 2;