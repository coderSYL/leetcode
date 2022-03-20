# MySQL
# leetcode 512
# https://leetcode-cn.com/problems/game-play-analysis-ii/

SELECT
    player_id,
    A.device_id
FROM Activity A
JOIN (
    SELECT
        player_id,
        device_id,
        MIN(event_date) AS event_date
    FROM Activity
    GROUP BY player_id
) tmp USING (player_id, event_date);