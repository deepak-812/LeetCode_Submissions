/* Write your T-SQL query statement below */
select 'Low Salary' as category, count(if(income<20000,1,null)) as accounts_count from accounts
union all
select 'Average Salary' as category,count(if(income between 20000 and 50000,1,null)) as accounts_count from accounts
union all
select 'High Salary' as category, count(if(income>50000,1,null)) as accounts_count from accounts;