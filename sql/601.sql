# MySQL
# leetcode 601
# https://leetcode-cn.com/problems/human-traffic-of-stadium/

SELECT
	id, visit_date, people
FROM(
	SELECT 
        id, visit_date, people, COUNT(*) over(PARTITION BY tag) AS cnt_tag
    FROM(
		SELECT 
            id, visit_date, people, id - ROW_NUMBER() OVER(ORDER BY id) AS tag
        FROM 
            Stadium
        WHERE
            people >= 100
    ) t1
) t2
WHERE cnt_tag >= 3
ORDER BY visit_date;