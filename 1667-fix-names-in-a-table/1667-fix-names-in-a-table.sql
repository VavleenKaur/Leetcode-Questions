/* Write your PL/SQL query statement below */
SELECT user_id AS user_id ,INITCAP(name) AS name from Users
order by user_id;