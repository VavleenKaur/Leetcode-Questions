# Write your MySQL query statement below
select c.id as id from Weather c join Weather p
on datediff(c.recordDate,p.recordDate)=1
where c.temperature>p.temperature