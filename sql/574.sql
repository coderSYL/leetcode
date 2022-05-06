# MySQL
# leetcode 574
# https://leetcode-cn.com/problems/winning-candidate/

SELECT
	c.name
FROM (
		SELECT 
			candidateId,
			COUNT(candidateId) as cnt 
		FROM Vote
		GROUP BY candidateId
		ORDER BY cnt DESC
		LIMIT 0,1
	) AS new_table
LEFT JOIN Candidate c
	ON c.id = new_table.candidateId;