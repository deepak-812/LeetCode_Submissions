SELECT d.name AS Department,
       e.name AS Employee,
       e.salary AS Salary
FROM employee e
INNER JOIN department d ON d.id = e.departmentId
LEFT JOIN employee e2 ON e.departmentId = e2.departmentId AND e.salary < e2.salary
WHERE e2.id IS NULL;