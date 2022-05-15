# MySQL
# leetcode 1097
# https://leetcode.cn/problems/game-play-analysis-v/

SELECT 
    t.install_dt,
    COUNT(*) AS installs,
    ROUND(COUNT(event_date)/COUNT(*), 2) AS Day1_retention
FROM(
    SELECT
        player_id,
        MIN(event_date) as install_dt
    FROM activity
    GROUP BY player_id) t
LEFT JOIN activity a
    ON a.event_date = DATE_ADD(t.install_dt, INTERVAL 1 DAY)
        AND a.player_id = t.player_id
GROUP BY install_dt;