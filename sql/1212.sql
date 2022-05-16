# MySQL
# leetcode 1212
# https://leetcode.cn/problems/team-scores-in-football-tournament/

SELECT
    t.team_id,
    t.team_name,
    IFNULL(SUM(p.pts), 0) AS num_points
FROM teams t
LEFT JOIN (
    SELECT
        host_team AS team_id,
        CASE
            WHEN host_goals > guest_goals THEN 3
            WHEN host_goals = guest_goals THEN 1
            ELSE 0
        END AS pts
    FROM matches
    UNION ALL
    SELECT
        guest_team AS team_id,
        CASE
            WHEN host_goals < guest_goals THEN 3
            WHEN host_goals = guest_goals THEN 1
            ELSE 0
        END AS pts
    FROM matches
) p USING (team_id)
GROUP BY team_id
ORDER BY num_points DESC, team_id ASC;