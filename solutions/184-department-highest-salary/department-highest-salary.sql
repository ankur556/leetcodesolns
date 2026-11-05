SELECT 
    t1.name AS Department, 
    t2.name AS Employee, 
    t2.salary AS Salary
FROM Employee t2 
JOIN Department t1 
    ON t2.departmentId = t1.id
WHERE (t2.departmentId, t2.salary) IN (
    SELECT departmentId, MAX(salary)
    FROM Employee
    GROUP BY departmentId
);