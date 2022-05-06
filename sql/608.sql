# MySQL
# leetcode 608
# https://leetcode-cn.com/problems/tree-node/

SELECT
	id,
CASE WHEN p_id IS null THEN 'Root'
	 WHEN id IN (select distinct p_id from tree) THEN 'Inner' 
	 ELSE 'Leaf'
END AS type
FROM tree;