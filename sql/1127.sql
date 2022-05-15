# MySQL
# leetcode 1127
# https://leetcode.cn/problems/user-purchase-platform/

SELECT 
    t2.spend_date,
    t1.platform,
    sum(if(t1.platform = t2.platform, amount, 0)) AS total_amount,
    count(if(t1.platform = t2.platform, 1, NULL)) AS total_users
FROM (
    SELECT 'mobile' AS platform UNION
    SELECT 'desktop' AS platform UNION
    SELECT 'both' AS platform 
) t1, 
(
    SELECT 
        user_id,
        spend_date, 
        if(count(platform) = 2, 'both', platform) AS platform,
        sum(amount) AS amount
    FROM spending
    GROUP BY user_id, spend_date
) t2 
GROUP BY t2.spend_date, t1.platform;