# MySQL
# leetcode 1193
# https://leetcode.cn/problems/monthly-transactions-i/

SELECT
    LEFT(trans_date, 7) AS month,
    country,
    COUNT(*) AS trans_count,
    COUNT(IF(state = 'approved', amount, NULL)) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(IF(state = 'approved', amount, 0)) AS approved_total_amount
FROM transactions
GROUP BY month, country;