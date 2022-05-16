# MySQL
# leetcode 1205
# https://leetcode.cn/problems/monthly-transactions-ii/

SELECT
    month,
    country,
    SUM(IF(tag = 1, 1, 0)) AS approved_count,
    SUM(IF(tag = 1, amount, 0)) AS approved_amount,
    SUM(IF(tag = 2, 1, 0)) AS chargeback_count,
    SUM(IF(tag = 2, amount, 0)) AS chargeback_amount
FROM (
    (
        SELECT
            LEFT(trans_date, 7) AS month,
            country,
            1 AS tag,
            amount
        FROM transactions
        WHERE state = 'approved'
    )
    UNION ALL
    (
        SELECT LEFT(c.trans_date, 7) AS month,
            country,
            2 AS tag,
            t.amount
        FROM chargebacks c 
        LEFT JOIN transactions t
        ON c.trans_id = t.id
    )
) t
GROUP BY month, t.country;