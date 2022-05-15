# MySQL
# leetcode 1126
# https://leetcode.cn/problems/active-businesses/

SELECT business_id
FROM events e
JOIN (
    SELECT event_type, AVG(occurences) AS avg_num
    FROM events
    GROUP BY event_type) t USING (event_type)
WHERE e.occurences > t.avg_num
GROUP BY business_id
HAVING COUNT(*) >= 2;