# MySQL
# leetcode 602
# https://leetcode-cn.com/problems/friend-requests-ii-who-has-the-most-friends/

SELECT id, SUM(cnt) AS num
FROM (
	SELECT accepter_id AS id, COUNT(*) AS cnt
	FROM RequestAccepted ra
	GROUP BY accepter_id
UNION ALL
	SELECT requester_id AS id, COUNT(*) AS cnt
	FROM RequestAccepted ra
	GROUP BY requester_id
) t2
GROUP BY id
ORDER BY num DESC
LIMIT 1;