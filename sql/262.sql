# MySQL
# leetcode 262
# https://leetcode-cn.com/problems/trips-and-users/

SELECT
    request_at AS Day,
    ROUND(1 - SUM(status = 'completed') /COUNT(*), 2) AS 'Cancellation Rate'
FROM Trips AS t
WHERE client_id NOT IN # 乘客没被ban
		(
			SELECT users_id
			FROM Users
			WHERE banned = 'Yes'
		)
	AND driver_id NOT IN # 司机没被ban
		(
			SELECT users_id
			FROM Users
			WHERE banned = 'Yes'
		)
    AND request_at BETWEEN '2013-10-01' AND '2013-10-03' # 指定日期内
GROUP  BY request_at;