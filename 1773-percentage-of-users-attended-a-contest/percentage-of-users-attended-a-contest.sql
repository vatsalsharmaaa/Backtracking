-- # Write your MySQL query statement below
-- SELECT r.contest_id, ROUND(count(contest_id)/count(*),2)*100 as percentage
-- FROM Users u
-- right join 
-- Register r
-- on u.user_id=r.user_id
-- group by r.contest_id
-- order by percentage DESC, r.contest_id ASC;

SELECT 
    r.contest_id,
    ROUND(COUNT(*) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register r
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;