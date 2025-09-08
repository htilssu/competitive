SELECT
    (SELECT TOP 1 Salary
     FROM Employee
     WHERE Salary < (SELECT MAX(Salary) FROM Employee)
     ORDER BY Salary DESC
    ) AS SecondHighestSalary;