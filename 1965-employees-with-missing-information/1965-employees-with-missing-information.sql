# Write your MySQL query statement below
SELECT e.employee_id as employee_id from Employees e
where e.employee_id not in
(
    SELECT s.employee_id from Salaries s
)
union
SELECT s.employee_id as employee_id from Salaries s
where s.employee_id not in
(
    SELECT e.employee_id from Employees e
)
order by employee_id;
