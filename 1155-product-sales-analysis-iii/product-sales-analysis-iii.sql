Select product_id, year as first_year,quantity,price
from Sales
where (product_id,year) IN(
    SELECT product_id, MIN(Year) as f_year
    from Sales
    Group by product_id
)

