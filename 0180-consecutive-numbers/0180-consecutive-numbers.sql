/* Write your T-SQL query statement below */
select distinct num as ConsecutiveNums from (
    select *, lag(num,1) over(order by id) -num as prv,
              lag(num,2) over(order by id) -num as prv2, 
              lead(num,1) over(order by id) -num as nxt, 
              lead(num,2) over(order by id) -num as nxt2 
    from logs) x
where 
(prv=0 and prv2=0)
or 
(prv=0 and nxt=0)
or 
(nxt=0 and nxt2=0)
group by (num) having count(num)>=1