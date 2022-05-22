# MySQL
# leetcode 1988
# https://leetcode.cn/problems/find-cutoff-score-for-each-school/

SELECT
    s.school_id,
    IFNULL(MIN(e.score), -1) AS score
FROM schools s 
LEFT JOIN exam e 
	ON e.student_count <= s.capacity
GROUP BY school_id;