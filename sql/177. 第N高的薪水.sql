CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N := N - 1;
    RETURN (
        # Write your MySQL query statement below.
        SELECT IFNULL(
            (SELECT DISTINCT salary
                FROM employee
                ORDER BY salary DESC
                LIMIT 1 OFFSET N),
            null
        )
    );
END