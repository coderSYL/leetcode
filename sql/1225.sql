# MySQL
# leetcode 1225
# https://leetcode.cn/problems/report-contiguous-dates/

SELECT 
    IF(state = 1, 'failed', 'succeeded') AS period_state,
    MIN(date) AS start_date,
    MAX(date) AS end_date
FROM(
	    (SELECT
	        1 AS state,
	        fail_date AS date,
	        SUBDATE(fail_date, ROW_NUMBER() OVER(ORDER BY fail_date)) AS tag
	    FROM failed
	    WHERE YEAR(fail_date) = '2019')
	    UNION ALL
	    (SELECT
	        2 AS state,
	        success_date   AS date,
	        SUBDATE(success_date, ROW_NUMBER() OVER(ORDER BY success_date)) AS tag
	    FROM succeeded
	    WHERE YEAR(success_date) = '2019'
	    )
	) t1
GROUP BY state, tag
ORDER BY start_date;