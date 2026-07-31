# Write your MySQL query statement below
select t2.reports_to as employee_id ,t1.name , count(t1.employee_id) as reports_count,round(avg(t2.age),0) as average_age
from Employees t1 join Employees t2
on t1.employee_id=t2.reports_to
group by t2.reports_to
order by t2.reports_to asc