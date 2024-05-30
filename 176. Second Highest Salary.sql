SELECT CASE 
    WHEN COUNT(*) = 1 THEN NULL
    ELSE (SELECT MAX(salary) FROM employee WHERE salary < (SELECT MAX(salary) FROM employee))
    END AS SecondHighestSalary
FROM employee;
