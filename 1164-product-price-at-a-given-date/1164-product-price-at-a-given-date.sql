/* Write your T-SQL query statement below */
select product_id, new_price as price from (select *, row_number() over(partition by product_id order by change_date desc) as rn from products where change_date<='2019-08-16') x where rn=1
union 
select product_id, 10 from products where product_id not in (select product_id from products where change_date<='2019-08-16');