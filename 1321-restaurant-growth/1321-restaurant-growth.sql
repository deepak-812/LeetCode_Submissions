declare @maxDate date=(select max(visited_on) from customer),
         @minDate date=(select min(visited_on) from customer);


select visited_on, 
   (select sum(amount) as amount from customer c 
   where 
   c.visited_on between dateadd(day,-6,c2.visited_on) and c2.visited_on) amount,
   (select cast(sum(amount*1.00)/7 as decimal(38,2)) as average_amount from customer c 
   where 
   c.visited_on 
   between
   dateadd(day,-6,c2.visited_on) 
   and 
   c2.visited_on) average_amount
 from customer c2 where visited_on>=dateadd(day,6,@minDate) group by visited_on;