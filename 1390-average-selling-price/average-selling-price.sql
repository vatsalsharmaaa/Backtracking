# Write your MySQL query statement below
Select p1.product_id ,  IFNULL(ROUND( SUM(u1.units*p1.price) / SUM(u1.units),2),0) as average_price
from Prices p1 
left join 
UnitsSold u1
on p1.product_id=u1.product_id
AND u1.purchase_date BETWEEN p1.start_date AND p1.end_date
group by product_id