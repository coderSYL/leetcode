# MySQL
# leetcode 175
# https://leetcode-cn.com/problems/combine-two-tables/

SELECT
    P.firstName,
    P.lastName,
    A.city,
    A.state
FROM Person P
LEFT JOIN Address A USING (PersonId);