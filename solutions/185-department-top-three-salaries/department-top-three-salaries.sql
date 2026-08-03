# Write your MySQL query statement below
select d.name as Department,e.name as Employee ,e.salary as Salary from
Employee e join Department d
on e.departmentid=d.id
where 3>(
    select count(distinct(e2.salary))
    from employee e2
    where e.salary<e2.salary and e.departmentId=e2.departmentId
);
