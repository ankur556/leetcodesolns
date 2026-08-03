# Write your MySQL query statement below
select "Low Salary" as category,ifnull(count(t1.income),0) as accounts_count from Accounts t1 where t1.income<20000
union
select "High Salary" as category,ifnull(count(t2.income),0) as accounts_count from Accounts t2 where t2.income>50000
union
select "Average Salary" as category,ifnull(count(t3.income),0) as accounts_count from Accounts t3 where t3.income<=50000 and t3.income>=20000
order by accounts_count desc