/* Write your T-SQL query statement below */
with cte as(
 select buyer_id, count(buyer_id) as cnt from orders where year(order_date)=2019 group by buyer_id
), cte2 as (
 select u.user_id buyer_id, join_date , coalesce(cnt,0) as orders_in_2019 from users u left join cte c on c.buyer_id=u.user_id 
)
select * from cte2;