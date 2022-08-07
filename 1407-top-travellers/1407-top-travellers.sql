# Write your MySQL query statement below
SELECT Users.name, SUM(
                      CASE 
                       WHEN Rides.distance is null THEN 0
                       ELSE Rides.distance
                      END
                      ) travelled_distance from Users LEFT JOIN Rides 
ON Users.id= Rides.user_id
group by Users.id
order by travelled_distance DESC, Users.name;