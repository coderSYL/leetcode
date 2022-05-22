# MySQL
# leetcode 1699
# https://leetcode.cn/problems/number-of-calls-between-two-persons/

SELECT
    IF(from_id < to_id, from_id, to_id) AS person1,
    IF(from_id > to_id, from_id, to_id) AS person2,
    COUNT(*) AS call_count,
    SUM(duration) AS total_duration
FROM calls
GROUP BY person1, person2;