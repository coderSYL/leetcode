# MySQL
# leetcode 1440
# https://leetcode.cn/problems/evaluate-boolean-expression/

SELECT
    e.*,
    CASE operator
        WHEN '<' THEN IF(l.value < r.value, 'true', 'false')
        WHEN '>' THEN IF(l.value > r.value, 'true', 'false')
        ELSE IF(l.value = r.value, 'true', 'false')
    END AS value
FROM expressions e 
LEFT JOIN variables l
    ON e.left_operand = l.name
LEFT JOIN variables r
    ON e.right_operand = r.name;