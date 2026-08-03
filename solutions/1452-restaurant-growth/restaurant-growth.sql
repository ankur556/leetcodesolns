# Write your MySQL query statement below
select t1.visited_on ,
(select sum(amount) from Customer t3 where datediff(t1.visited_on,t3.visited_on)<=6 and datediff(t1.visited_on,t3.visited_on)>=0) as amount ,
round(((select sum(amount) from Customer t3 where datediff(t1.visited_on,t3.visited_on)<=6 and datediff(t1.visited_on,t3.visited_on)>=0))/((select count(distinct(t3.visited_on)) from Customer t3 where datediff(t1.visited_on,t3.visited_on)<=6 and datediff(t1.visited_on,t3.visited_on)>=0)),2) as average_amount
from Customer t1
where datediff(t1.visited_on,(select min(visited_on) from Customer))>=6
group by t1.visited_on