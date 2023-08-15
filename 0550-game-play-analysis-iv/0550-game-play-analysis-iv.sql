declare @pl_cnt  int,
        @tot_cnt int;
        

select @tot_cnt=count(distinct player_id) from activity;

select @pl_cnt=count(a.player_id) from activity a inner join (select player_id, min(event_date) minDate from activity group by player_id) x on x.player_id=a.player_id and dateadd(day,1,x.minDate)=a.event_date;

select cast((@pl_cnt)/(@tot_cnt*1.00) as decimal(38,2)) as fraction;