# MySQL
# leetcode 1407
# https://leetcode.cn/problems/top-travellers/

SELECT u.name,
    IFNULL(SUM(r.distance), 0) AS travelled_distance
FROM rides r
RIGHT JOIN users u ON u.id = r.user_id
GROUP BY user_id
ORDER BY travelled_distance DESC, name ASC;