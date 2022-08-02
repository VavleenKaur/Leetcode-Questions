# Write your MySQL query statement below
SELECT s.name from Salesperson s
where s.sales_id not in
(select o.sales_id from Orders o where o.com_id=(select c.com_id from Company c where c.name="RED"));