# Write your MySQL query statement below
SELECT s.user_id, IFNULL(ROUND(SUM(action='confirmed')/count(*),2),0.00) as confirmation_rate
from Signups as s
left join
Confirmations as c
on s.user_id=c.user_id
group by s.user_id;