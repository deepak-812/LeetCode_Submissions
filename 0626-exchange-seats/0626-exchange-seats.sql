/* Write your T-SQL query statement below */
declare @v_maxVal int;
 select @v_maxVal=max(id) from seat;
select * from 
    (select iif(id%2=1 and id=@v_maxVal,id,iif(id%2=0,id-1,id+1)) id, student from seat) x order by id
 