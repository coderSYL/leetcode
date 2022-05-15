# MySQL
# leetcode 1581
# https://leetcode.cn/problems/customer-who-visited-but-did-not-make-any-transactions/

SELECT customer_id, COUNT(*) count_no_trans
FROM visits v
WHERE visit_id NOT IN (
    SELECT DISTINCT visit_id
    FROM transactions
)
GROUP BY customer_id;

# faster method
-- SELECT customer_id, COUNT(*) count_no_trans
-- FROM visits v
-- LEFT JOIN  transactions t USING (visit_id)
-- WHERE t.amount IS NULL
-- GROUP BY customer_id;