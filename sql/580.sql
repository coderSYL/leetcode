# MySQL
# leetcode 580
# https://leetcode-cn.com/problems/count-student-number-in-departments/

SELECT
	d.dept_name,
	IFNULL(COUNT(s.dept_id),0) AS student_number
FROM student s
RIGHT JOIN department d 
	USING (dept_id)
GROUP BY dept_id
ORDER BY student_number DESC, d.dept_name ASC;