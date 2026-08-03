# Write your MySQL query statement below
select round(count(distinct(t1.player_id))/(select count(distinct(player_id)) from Activity),2) as fraction
from activity t1 
where datediff(t1.event_date,(select min(event_date) from Activity t2 where t2.player_id=t1.player_id))=1;