# MySQL
# leetcode 1459
# https://leetcode.cn/problems/rectangles-area/

SELECT
    p1.id AS P1,
    p2.id AS P2,
    ABS(p1.x_value - p2.x_value) * ABS(p1.y_value - p2.y_value) AS AREA
FROM points p1, points p2
WHERE p1.id < p2.id
    AND p1.x_value != p2.x_value
    AND p1.y_value != p2.y_value
ORDER BY AREA DESC, p1.id ASC, p2.id ASC;