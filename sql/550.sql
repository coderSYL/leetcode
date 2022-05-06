# MySQL
# leetcode 550
# https://leetcode-cn.com/problems/game-play-analysis-iv/

SELECT ROUND(COUNT(a.event_date)/COUNT(t.player_id), 2) AS fraction
FROM Activity a
RIGHT JOIN (
		SELECT player_id, MIN(event_date) AS first_login
		FROM Activity
		GROUP BY player_id
	) t
	ON a.player_id = t.player_id
		AND DATE_ADD(t.first_login, INTERVAL 1 DAY) = a.event_date;