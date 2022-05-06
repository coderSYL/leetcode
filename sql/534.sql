# MySQL
# leetcode 534
# https://leetcode-cn.com/problems/game-play-analysis-iii/

SELECT
	player_id,
	event_date,
	SUM(games_played) over(PARTITION BY player_id ORDER BY event_date)AS games_played_so_far 
FROM Activity
# ORDER BY player_id, event_date;