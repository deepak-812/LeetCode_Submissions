with cte as (
 select distinct product_id, min(year) over(partition by product_id order by year) as first_year from sales
), cte2 as (
 select c.product_id, first_year, quantity, price from sales s inner join cte c on c.product_id=s.product_id and c.first_year=year
)
select * from cte2;