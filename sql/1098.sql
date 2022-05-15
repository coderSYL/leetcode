# MySQL
# leetcode 1098
# https://leetcode.cn/problems/unpopular-books/

SELECT book_id,name
FROM books b 
LEFT JOIN (
    SELECT
        book_id,
        SUM(quantity) AS cnt 
    FROM orders
    WHERE dispatch_date >= "2018-06-23"
    GROUP BY book_id) t USING (book_id)
WHERE b.available_from <= "2019-05-23"
    AND (t.cnt < 10 OR t.cnt IS NULL)