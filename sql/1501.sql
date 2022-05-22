# MySQL
# leetcode 1501
# https://leetcode.cn/problems/countries-you-can-safely-invest-in/

SELECT c.name AS country
FROM country c 
LEFT JOIN(
    SELECT LEFT(p.phone_number, 3) AS country_code, AVG(t.duration) AS avg
    FROM (
        SELECT caller_id AS id, duration FROM calls
        UNION ALL
        SELECT callee_id AS id, duration FROM calls
    ) t 
    LEFT JOIN person p USING (id)
    GROUP BY country_code
) t2 USING (country_code)
WHERE t2.avg > (SELECT AVG(duration) FROM calls);