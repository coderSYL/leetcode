# MySQL
# leetcode 614
# https://leetcode-cn.com/problems/second-degree-follower/

SELECT DISTINCT
    t1.followee AS "follower",
    t1.num
FROM (
	SELECT
		followee,
		COUNT(*) AS num
	FROM follow
	GROUP BY followee
) t1
JOIN follow f 
ON t1.followee = f.follower
ORDER BY t1.followee ASC;