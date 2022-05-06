# MySQL
# leetcode 618
# https://leetcode-cn.com/problems/students-report-by-geography/

SELECT
	*,
	ROW_NUMBER() OVER (PARTITION BY continent) AS id
FROM student