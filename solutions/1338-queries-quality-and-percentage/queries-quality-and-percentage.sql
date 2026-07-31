# Write your MySQL query statement below
select query_name,round(ifnull(avg(rating/position),0.00),2) as quality,
round(100*sum(rating<3)/count(*),2) as poor_query_percentage
from Queries
group by query_name