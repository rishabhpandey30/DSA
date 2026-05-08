# Write your MySQL query statement below
select eu.unique_id, e.name from Employees e
Left join EmployeeUNI eu
on e.id = eu.id