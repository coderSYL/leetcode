# MySQL
# leetcode 1112
# https://leetcode.cn/problems/highest-grade-for-each-student/

SELECT
    student_id,
    MIN(course_id) AS course_id,
    grade
FROM enrollments e
JOIN(
    SELECT
        student_id,
        MAX(grade) AS max_grade
    FROM enrollments
    GROUP BY student_id) t
    USING (student_id)
WHERE e.grade = t.max_grade
GROUP BY e.student_id
ORDER BY student_id;