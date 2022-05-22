# MySQL
# leetcode 1555
# https://leetcode.cn/problems/bank-account-summary/

SELECT 
    u.user_id,
    u.user_name,
    IFNULL(SUM(t.credit), 0) + u.credit AS credit,
    IF(IFNULL(SUM(t.credit), 0) + u.credit < 0, 'Yes', 'No') AS credit_limit_breached
FROM users u 
LEFT JOIN(
    SELECT paid_by AS user_id, -amount AS credit
    FROM transactions
    UNION ALL
    SELECT paid_to AS user_id, amount AS credit
    FROM transactions
) t USING (user_id)
    GROUP BY (user_id);