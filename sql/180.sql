# MySQL
# leetcode 180
# https://leetcode-cn.com/problems/consecutive-numbers/
# 偷题解里的

SELECT DISTINCT Num AS ConsecutiveNums
FROM (
	SELECT Num,COUNT(1) as SerialCount FROM 
		(	
			SELECT Id,Num,
				row_number() over(ORDER BY Id) - # 按Id的顺序的行号
				ROW_NUMBER() over(partition by Num ORDER BY Id) # 先按Num分组，然后按Id排序
				 AS SerialNumberSubGroup
			FROM logs
		) AS Sub
	GROUP BY Num,SerialNumberSubGroup
	HAVING COUNT(1) >= 3
) AS Result;