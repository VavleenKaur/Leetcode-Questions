# Write your MySQL query statement below
Select distinct stock_name,sum(
    CASE 
    WHEN operation="BUY" THEN (-price)
    ELSE price
    END
)   AS "capital_gain_loss"
from Stocks
group by 1;