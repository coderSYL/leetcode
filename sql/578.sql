# MySQL
# leetcode 578
# https://leetcode-cn.com/problems/get-highest-answer-rate-question/

SELECT
	survey_log
FROM(
	SELECT
		question_id AS survey_log,
		SUM(action = "answer")/SUM(action = "show") as cnt
	FROM SurveyLog
	GROUP BY question_id
	ORDER BY cnt DESC, survey_log
    LIMIT 0,1
) AS new_table;