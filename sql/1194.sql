# MySQL
# leetcode 1194
# https://leetcode.cn/problems/tournament-winners/
# 方法略繁复

SELECT GROUP_ID, PLAYER_ID
FROM (
    SELECT 
        p.group_id,
        p.player_id,
        ROW_NUMBER() OVER (PARTITION BY group_id ORDER BY SUM(IFNULL(t1.score,0) + IFNULL(t2.score,0)) DESC, player_id ASC) AS rk
    FROM players p
    LEFT JOIN (
        SELECT
            first_player AS player_id,
            SUM(first_score) AS score
        FROM matches m
        GROUP BY m.first_player
    ) t1 USING (player_id)
    LEFT JOIN (
        SELECT
            second_player AS player_id,
            SUM(second_score) AS score
        FROM matches m
        GROUP BY m.second_player
    ) t2 USING (player_id)
    GROUP BY player_id
) t WHERE rk = 1;