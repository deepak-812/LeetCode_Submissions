/* Write your T-SQL query statement below */
with cte as 
(select requester_id as id, count(requester_id) cntfrnd from RequestAccepted where accepter_id is not null group by requester_id
union all
select accepter_id as id, count(accepter_id) cntfrnd from RequestAccepted where requester_id is not null group by accepter_id
)
select top 1 id, sum(cntfrnd) num from cte group by id order by num desc, id asc;