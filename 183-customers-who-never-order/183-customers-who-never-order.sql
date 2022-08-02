# Write your MySQL query statement below
SELECT Customers.name AS Customers
FROM Customers
LEFT JOIN Orders
ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL ;