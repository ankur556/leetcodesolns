# Write your MySQL query statement below
select t1.id,t2.student
from Seat t1 join  Seat t2
on (t1.id%2=1 and t1.id=t2.id-1)or (t1.id%2=0 and t1.id=t2.id+1)

union 
select id,student
from seat 
where id%2=1 and id=(select max(id)from Seat)
order by id asc