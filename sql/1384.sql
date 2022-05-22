# MySQL
# leetcode 1384
# https://leetcode.cn/problems/total-sales-amount-by-year/

SELECT
    s.product_id,
    p.product_name,
    t.report_year,
    s.average_daily_sales * 
    (DATEDIFF(IF(YEAR(s.period_end) = t.report_year, s.period_end, CONCAT(t.report_year, '-12-31')),
     IF(YEAR(s.period_start) = t.report_year, s.period_start, CONCAT(t.report_year, '-01-01'))) + 1) AS total_amount
FROM sales s
JOIN (
    SELECT '2018' AS report_year, 365 AS days
    UNION ALL
    SELECT '2019' AS report_year, 365 AS days
    UNION ALL
    SELECT '2020' AS report_year, 366 AS days
) t
    ON t.report_year <= YEAR(s.period_end)
     AND t.report_year >= YEAR(s.period_start)
JOIN product p USING (product_id)
ORDER BY product_id,report_year;