# Write your MySQL query statement below
SELECT user_id AS user_id ,CONCAT(UPPER(LEFT(name,1)),LOWER(RIGHT(name,LENGTH(name)-1)))AS name from Users
order by user_id;