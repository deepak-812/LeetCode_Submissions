/* Write your T-SQL query statement below */
select name from employee where id in (select managerId from employee group by managerId having count(managerID)>=5);