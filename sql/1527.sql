# MySQL
# leetcode 1527
# https://leetcode.cn/problems/patients-with-a-condition/

SELECT *
FROM patients
WHERE conditions REGEXP ' DIAB1|^DIAB1';