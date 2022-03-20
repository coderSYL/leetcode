# MySQL
# leetcode 613
# https://leetcode-cn.com/problems/shortest-distance-in-a-line/

SELECT p1.x - p2.x AS shortest
FROM point p1, point p2
WHERE p1.x > p2.x
ORDER BY shortest
LIMIT 0,1;