# Write your MySQL query statement below
SELECT s.name from Salesperson s
where s.sales_id not in
(select o.sales_id from Orders o INNER JOIN Company c on o.com_id=c.com_id where c.name="RED");