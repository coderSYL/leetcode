# MySQL
# leetcode 197
# https://leetcode-cn.com/problems/rising-temperature/

# 学习到了新函数 date_add()，此处用adddate()同样也行
SELECT w1.id
FROM Weather w1
JOIN Weather w2
    ON w1.recordDate = date_add(w2.recordDate, interval 1 day)
WHERE w1.Temperature > w2.Temperature;