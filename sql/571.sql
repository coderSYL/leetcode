# MySQL
# leetcode 571
# https://leetcode-cn.com/problems/find-median-given-frequency-of-numbers/

SELECT ROUND(avg(num), 1) AS median
FROM (
		SELECT
			num,
			SUM(frequency) OVER(ORDER BY num ASC) AS id1,
			SUM(frequency) OVER(ORDER BY num DESC) AS id2
		FROM Numbers
	) AS t1,
	(
		SELECT SUM(frequency) AS total
		FROM Numbers	
	) AS t2
WHERE t1.id1 >= total / 2
	AND t1.id2 >= total / 2;