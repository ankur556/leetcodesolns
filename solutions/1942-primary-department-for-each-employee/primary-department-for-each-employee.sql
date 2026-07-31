-- Scenario 1: Employees belonging to only 1 department
SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id
HAVING COUNT(department_id) = 1

UNION

-- Scenario 2: Employees with multiple departments where primary_flag is 'Y'
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y';