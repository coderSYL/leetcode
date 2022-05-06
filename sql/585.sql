# MySQL
# leetcode 585
# https://leetcode-cn.com/problems/investments-in-2016/

SELECT ROUND(SUM(TIV_2016), 2) AS TIV_2016
FROM insurance i
JOIN(
		SELECT
			LAT,
			LON,
			COUNT(*) AS cnt
		FROM insurance
		GROUP BY LAT,LON
	) AS t1
	USING (LAT, LON)
JOIN(
		SELECT 
			TIV_2015,
			COUNT(*) AS cnt 
		FROM insurance
		GROUP BY TIV_2015
	) AS t2
	USING(TIV_2015)
WHERE t1.cnt = 1 AND t2.cnt > 1;
