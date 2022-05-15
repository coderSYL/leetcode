# MySQL
# leetcode 1050
# https://leetcode-cn.com/problems/actors-and-directors-who-cooperated-at-least-three-times/

SELECT
	actor_id,
	director_id
FROM actorDirector
GROUP BY actor_id, director_id
HAVING COUNT(*) > 2;