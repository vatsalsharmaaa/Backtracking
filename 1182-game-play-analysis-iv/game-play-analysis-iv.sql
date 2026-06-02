SELECT ROUND( count(DISTINCT player_id) / (select count(DISTINCT player_id) from Activity),2 ) as fraction
FROM Activity

Where(player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) IN(
SELECT player_id, MIN(event_date) as first_login
from Activity 
group by player_id);