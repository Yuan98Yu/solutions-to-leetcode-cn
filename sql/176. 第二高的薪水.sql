SELECT IFNULL(
    (SELECT max(salary) FROM employee
        WHERE salary < (SELECT max(salary) FROM employee)),
    null) as SecondHighestSalary;

SELECT IFNULL(
    (SELECT DISTINCT salary FROM employee
        ORDER BY salary DESC
        LIMIT 1 OFFSET 1),
    null) as SecondHighestSalary;