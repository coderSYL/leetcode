# MySQL
# leetcode 626
# https://leetcode-cn.com/problems/exchange-seats


SELECT
	(CASE
		WHEN MOD(id, 2) = 0 THEN id - 1
		WHEN MOD(id, 2) = 1 AND id = m.max_id THEN id
		ELSE id + 1
	END) AS id,
	student
FROM seat, (SELECT COUNT(*) AS max_id FROM seat) m
ORDER BY id;