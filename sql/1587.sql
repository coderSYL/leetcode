# MySQL
# leetcode 1587
# https://leetcode.cn/problems/bank-account-summary-ii/

SELECT u.name, IFNULL(t.balance, 0) AS balance
FROM users u
JOIN (
    SELECT account, SUM(amount) AS balance
    FROM transactions
    GROUP BY account
) t USING (account)
WHERE balance > 10000;