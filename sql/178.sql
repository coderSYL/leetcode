# MySQL
# leetcode 178
# https://leetcode-cn.com/problems/rank-scores/

SELECT 
	Score,
	dense_rank() over(order by Score desc) as 'Rank'
FROM Scores;