# Write your MySQL query statement below
-- select query_name, 
-- ROUND(AVG(SUM(rating/position)),2) as quality,
-- COUNT(select query_name where rating<3)/COUNT(select query_name)*100 as poor_query_percentage
-- from Queries
-- group by query_name;
SELECT query_name,
ROUND(SUM(rating / position) / COUNT(*), 2) AS quality,
ROUND( SUM(rating < 3) * 100 / COUNT(*),  2  ) AS poor_query_percentage
FROM Queries
WHERE query_name IS NOT NULL
GROUP BY query_name;