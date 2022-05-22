# MySQL
# leetcode 1341
# https://leetcode.cn/problems/movie-rating/
(
	SELECT u.name AS results
	FROM(
	    SELECT user_id, COUNT(*) AS cnt
	    FROM movierating
	    GROUP BY user_id
	    HAVING cnt >= (SELECT COUNT(*) AS cnt FROM movierating GROUP BY user_id ORDER BY cnt DESC LIMIT 1)
	) t1
	JOIN users u USING (user_id)
	ORDER BY name
	LIMIT 1
)
UNION
(
	SELECT m.title AS results
	FROM (
	    SELECT movie_id
	    FROM movierating
	    WHERE LEFT(created_at, 7) = '2020-02'
	    GROUP BY movie_id
	    HAVING AVG(rating) = (
	        SELECT AVG(rating) AS big
	        FROM movierating
	        WHERE LEFT(created_at, 7) = '2020-02'
	        GROUP BY movie_id
	        ORDER BY big DESC
	        LIMIT 1
	    )
	) t2
	LEFT JOIN movies m USING (movie_id)
	ORDER BY m.title
	LIMIT 1
);