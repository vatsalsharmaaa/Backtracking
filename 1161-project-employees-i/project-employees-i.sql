# Write your MySQL query statement below
select project_id, ROUND (AVG(experience_years) ,2) as average_years
from Project p1 
join 
Employee e1 on p1.employee_id= e1.employee_id
group by project_id