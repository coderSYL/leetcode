# MySQL
# leetcode 1204
# https://leetcode.cn/problems/last-person-to-fit-in-the-bus/

SELECT person_name
FROM (
    SELECT
        person_name,
        SUM(weight) OVER (ORDER BY turn ASC) AS sum
    FROM queue
) t
WHERE sum <= 1000
ORDER BY sum DESC
LIMIT 1;