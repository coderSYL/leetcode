# MySQL
# leetcode 1321
# https://leetcode.cn/problems/restaurant-growth/

SELECT distinct visited_on,sum_amount AS amount,round(average_amount,2) AS average_amount 
FROM(
    SELECT visited_on,
        SUM(amount) over(ORDER BY visited_on rows 6 preceding) AS sum_amount,
        AVG(amount) over(ORDER BY visited_on rows 6 preceding) AS average_amount
    FROM(
         SELECT visited_on, SUM(amount) AS amount 
         FROM customer
         GROUP BY visited_on
    )t1
)t2 
WHERE DATEDIFF(visited_on, (SELECT MIN(visited_on) FROM customer)) >= 6;